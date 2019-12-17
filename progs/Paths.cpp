#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <map>
#include <string>
#include <queue>
#include <list>
#include <climits>
using namespace std;

class Graph {
public:
    ~Graph();
    void addEdge(const string& sourceName, const string& destName, int cost);
    void printPath(const string& destName) const;
    void unweighted(const string& startName);
    void dijkstra(const string& startName);
    void negative(const string& startName);
    void acyclic(const string& startName);
private:
    struct Vertex {
        Vertex(const string& name);
        void addEdge(Vertex* v, int costs);
        string name;
        struct Edge {
            Edge(Vertex* v, int costs);
            Vertex* destination;
            int costs;
        };
        list<Edge> adjacent;
        // used for shortest-path algorithms
        void reset();
        void printPath() const;
        Vertex* previous;
        int costs;
        // used for dijkstra algorithm
        bool isProcessed; // Vertex is already isProcessed
        // used for negative algorithm
        unsigned int timesQueued; // number of time that this Vertex is placed on the queue  
        bool isOnQueue; // this Vertex is currently present on the queue
        // used for acyclic algorithm
        unsigned int indegree; // number of incomming edges for this Vertex
    };
    // getVertex creates a Vertex when it does not exists
    Vertex* getVertex(const string& vertexName);
    // find Vertex throws an exception when the Vertex does not exists
    Vertex* findVertex(const string& vertexName);
    const Vertex* findVertex(const string& vertexName) const;
    void reset();
    map<string, Vertex*> vertices;
    static const int INF = INT_MAX;
};

Graph::Vertex::Edge::Edge(Vertex* v, int costs): destination(v), costs(costs) {
}

Graph::Vertex::Vertex(const string& name): name(name) {
    reset();
}

void Graph::Vertex::addEdge(Vertex* v, int costs) {
    adjacent.push_back(Graph::Vertex::Edge(v, costs));
}

void Graph::Vertex::reset() {
    costs = INF;
    previous = 0;
    isProcessed = false;
    isOnQueue = false;
    timesQueued = 0;
    indegree = 0;
}

void Graph::Vertex::printPath() const {
    if (previous) {
        previous->printPath();
        cout << " to ";
    }
    cout << name;
}

Graph::~Graph() {
    for (auto& p : vertices) {
        delete p.second;
    }
}

void Graph::reset() {
    for (auto& p : vertices) {
        p.second->reset();
    }
}

Graph::Vertex* Graph::getVertex(const string& vertexName) {
    Vertex* v = vertices[vertexName];
    if (v == 0) {
        v = new Vertex(vertexName);
        vertices[vertexName] = v;
    }
    return v;
}

Graph::Vertex* Graph::findVertex(const string& vertexName) {
    auto itr = vertices.find(vertexName);
    if (itr == vertices.end())
        throw runtime_error(vertexName + " is not a vertex in this graph");
    return itr->second;
}

const Graph::Vertex* Graph::findVertex(const string& vertexName) const {
    auto itr = vertices.find(vertexName);
    if (itr == vertices.end())
        throw runtime_error(vertexName + " is not a vertex in this graph");
    return itr->second;
}

void Graph::addEdge(const string& sourceName, const string& destName, int cost) {
    Vertex* v = getVertex(sourceName);
    Vertex* w = getVertex(destName);
    v->addEdge(w, cost);
}

void Graph::printPath(const string& destinationName) const {
    const Vertex* destination = findVertex(destinationName);
    if (destination->costs == INF)
        cout << destinationName << " is unreachable";
    else {
        cout << "(Costs are: " << destination->costs << ") ";
        destination->printPath();
    }
    cout << endl;
}

void Graph::unweighted(const string& startName) {
    reset();
    Vertex* start = findVertex(startName);
    start->costs = 0;
    queue<Vertex*> q;
    q.push(start);
    while (!q.empty()) {
        Vertex* v = q.front();
        q.pop();
        for (auto& e : v->adjacent) {
            Vertex* w = e.destination;
            if (w->costs == INF) {
                w->costs = v->costs + 1;
                w->previous = v;
                q.push(w);
            }
        }
    }
}

void Graph::dijkstra(const string& startName) {
    reset();
    Vertex* start = findVertex(startName);
    start->costs = 0;
    auto ptrVectorGreater = [](Vertex* p, Vertex* q) { 
        return p->costs > q->costs; 
    };
    priority_queue<Vertex*, vector<Vertex*>, decltype(ptrVectorGreater)> pq(ptrVectorGreater);
    pq.push(start);
    while (!pq.empty()) {
        Vertex* v = pq.top();
        pq.pop();
        if (!v->isProcessed) {
            v->isProcessed = true;
            for (auto& e: v->adjacent) {
                Vertex* w = e.destination;
                int cvw = e.costs;
                if (cvw < 0) {
                    throw runtime_error("Graph has negative edges");
                }
                if (w->costs > v->costs + cvw) {
                    w->costs = v->costs + cvw;
                    w->previous = v;
                    pq.push(w);
                }
            }
        }
    }
}

void Graph::negative(const string& startName) {
    reset();
    Vertex* start = findVertex(startName);
    start->costs = 0;
    queue<Vertex*> q;
    q.push(start);
    start->isOnQueue = true;
    start->timesQueued += 1;
    while (!q.empty()) {
        Vertex* v = q.front();
        q.pop();
        v->isOnQueue = false;
        if (v->timesQueued > vertices.size()) {
            throw runtime_error("Negative cycle detected");
        }
        for (auto& e: v->adjacent) {
            Vertex* w = e.destination;
            int cvw = e.costs;
            if (w->costs > v->costs + cvw) {
                w->costs = v->costs + cvw;
                w->previous = v;
                w->timesQueued += 1;
                if (!w->isOnQueue) {
                    w->isOnQueue = true;
                    q.push(w);
                }
            }
        }
    }
}

void Graph::acyclic(const string& startName) {
    reset();
    Vertex* start = findVertex(startName);
    start->costs = 0;
    queue<Vertex*> q;
    // calculate all indegrees
    for (auto& p : vertices) {
        for (auto& e : p.second->adjacent) {
            e.destination->indegree += 1;
        }
    }
    // start with vertices with indegree 0
    for (auto& p : vertices) {
        Vertex* v = p.second;
        if (v->indegree == 0) {
            q.push(v);
        }
    }
    // for all vertices in queue
    decltype (vertices.size()) iterations;
    for (iterations = 0; !q.empty(); ++iterations) {
        Vertex* v = q.front();
        q.pop();
        for (auto& e: v->adjacent)  {
            Vertex* w = e.destination;
            int cvw = e.costs;
            w->indegree -= 1;
            if (w->indegree == 0) {
                q.push(w);
            }
            if (v->costs != INF && w->costs > v->costs + cvw) {
                w->costs = v->costs + cvw;
                w->previous = v;
            }
        }
    }
    if (iterations != vertices.size()) {
        throw runtime_error("Graph has a cycle!");
    }
}

int main() {
    const int pasen = 0;
    const int pinksteren = 1;
    try {
        while (pasen != pinksteren) {
            string fileName;
            do {
                cout << "p = positive (http://bd.eduweb.hhs.nl/algods/graph_positive.png)," << endl;
                cout << "n = negative (http://bd.eduweb.hhs.nl/algods/graph_negative.png)," << endl;
                cout << "a = acyclic  (http://bd.eduweb.hhs.nl/algods/graph_acyclic.png)," << endl;
                cout << "s = steden (acyclic) (http://bd.eduweb.hhs.nl/algods/graph_steden.png) or" << endl;
                cout << "q = quit." << endl;
                cout << "Choose graph: ";
                char c;
                cin >> c; cin.get();
                switch (c) {
                    case 'p':
                    case 'P': fileName = "graph_positive.txt"; break;
                    case 'n':
                    case 'N': fileName = "graph_negative.txt"; break;
                    case 'a':
                    case 'A': fileName = "graph_acyclic.txt"; break;
                    case 's':
                    case 'S': fileName = "graph_steden.txt"; break;
                    case 'q':
                    case 'Q': return 0;
                    default: cout << "Wrong input, try again." << endl;
                }
            } while (fileName.empty());
            char c;
            do {
                cout << "Show graph? (y/n): ";
                cin >> c; cin.get();
            } while (c != 'y' && c != 'n');
            if (c == 'y') {
                string baseName(fileName.substr(0, fileName.find(".txt")));
                system(("start http://bd.eduweb.hhs.nl/algods/" + baseName + ".png").c_str());
            }
            ifstream inFile(fileName);
            if (!inFile) {
                throw runtime_error("Cannot open " + fileName);
            }
            Graph g;
            cout << "Reading file ";
            string oneLine;
            while (getline(inFile, oneLine)) {
                string source, dest;
                int cost;
                istringstream st(oneLine);
                if (st >> source >> dest >> cost) {
                    g.addEdge(source, dest, cost);
                    cout << ".";
                }
                else {
                    cerr << "Bad line: " << oneLine << endl;
                }
            }
            cout << endl << "Enter start node: ";
            string startName;
            cin >> startName; cin.get();
            cout << "Enter destination node: ";
            string destName;
            cin >> destName; cin.get();
            cout << "Enter algorithm u = unweighted, d = dijkstra, n = negative or a = acyclic: ";
            char alg;
            cin >> alg; cin.get();
            try {
                switch (alg) {
                case 'u':
                case 'U': g.unweighted(startName); break;
                case 'd':
                case 'D': g.dijkstra(startName); break;
                case 'n':
                case 'N': g.negative(startName); break;
                case 'a':
                case 'A': g.acyclic(startName); break;
                case 'q':
                case 'Q': return false;
                default: throw runtime_error("Wrong input, try again.");
                }
                g.printPath(destName);
            }
            catch (const runtime_error& e) {
                cerr << e.what() << endl;
            }
        }
    }
    catch (const runtime_error& e) {
        cerr << e.what() << endl;
        cin.get(); 
        cin.get();
        return 1;
    }
    return 0;
}

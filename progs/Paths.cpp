import std;
using namespace std;

class Graph {
public:
    void add_edge(const string& source_name, const string& dest_name, int cost);
    void print_path(const string& dest_name) const;
    // four algorithms to calculate the shortest path:
    void unweighted(const string& start_name);
    void dijkstra(const string& start_name);
    void negative(const string& start_name);
    void acyclic(const string& start_name);
private:
    struct Vertex {
        Vertex(const string& name);
        void add_edge(shared_ptr<Vertex> v, int costs);
        string name;
        struct Edge {
            Edge(shared_ptr<Vertex> v, int costs);
            shared_ptr<Vertex> destination;
            int costs;
        };
        list<Edge> adjacent;
        // used for shortest-path algorithms
        void reset();
        void print_path() const;
        shared_ptr<Vertex> previous;
        int costs;
        // used for dijkstra algorithm
        bool is_processed; // Vertex is already processed
        // used for negative algorithm
        unsigned int times_queued; // number of time that this Vertex is placed on the queue  
        bool is_on_queue; // this Vertex is currently present on the queue
        // used for acyclic algorithm
        unsigned int indegree; // number of incomming edges for this Vertex
    };
    // get_vertex creates a Vertex when it does not exists
    shared_ptr<Vertex> get_vertex(const string& vertex_name);
    // find Vertex throws an exception when the Vertex does not exists
    shared_ptr<Vertex> find_vertex(const string& vertex_name);
    const shared_ptr<Vertex> find_vertex(const string& vertex_name) const;
    void reset();
    map<string, shared_ptr<Vertex>> vertices;
    static constexpr int INF {numeric_limits<int>::max()};
};

Graph::Vertex::Edge::Edge(shared_ptr<Vertex> v, int costs): destination{v}, costs{costs} {
}

Graph::Vertex::Vertex(const string& name): name{name} {
    reset();
}

void Graph::Vertex::add_edge(shared_ptr<Vertex> v, int costs) {
    adjacent.push_back(Graph::Vertex::Edge(v, costs));
}

void Graph::Vertex::reset() {
    costs = INF;
    previous = 0;
    is_processed = false;
    is_on_queue = false;
    times_queued = 0;
    indegree = 0;
}

void Graph::Vertex::print_path() const {
    if (previous) {
        previous->print_path();
        print(" to ");
    }
    print("{}", name);
}

void Graph::reset() {
    for (auto& p: vertices) {
        p.second->reset();
    }
}

Graph::shared_ptr<Vertex> Graph::get_vertex(const string& vertex_name) {
    shared_ptr<Vertex> v {vertices[vertex_name]};
    if (v == 0) {
        v = make_shared<Vertex>(vertex_name);
        vertices[vertex_name] = v;
    }
    return v;
}

Graph::shared_ptr<Vertex> Graph::find_vertex(const string& vertex_name) {
    auto itr {vertices.find(vertex_name)};
    if (itr == vertices.end())
        throw runtime_error {vertex_name + " is not a vertex in this graph"};
    return itr->second;
}

const Graph::shared_ptr<Vertex> Graph::find_vertex(const string& vertex_name) const {
    auto itr {vertices.find(vertex_name)};
    if (itr == vertices.end())
        throw runtime_error {vertex_name + " is not a vertex in this graph"};
    return itr->second;
}

void Graph::add_edge(const string& source_name, const string& dest_name, int cost) {
    shared_ptr<Vertex> v {get_vertex(source_name)};
    shared_ptr<Vertex> w {get_vertex(dest_name)};
    v->add_edge(w, cost);
}

void Graph::print_path(const string& destination_name) const {
    const shared_ptr<Vertex> destination {find_vertex(destination_name)};
    if (destination->costs == INF)
        print("{} is unreachable", destination_name);
    else {
        print("(Costs are: {}) ", destination->costs);
        destination->print_path();
    }
    print("\n");
}

void Graph::unweighted(const string& start_name) {
    reset();
    shared_ptr<Vertex> start {find_vertex(start_name)};
    start->costs = 0;
    queue<shared_ptr<Vertex>> q;
    q.push(start);
    while (!q.empty()) {
        shared_ptr<Vertex> v {q.front()};
        q.pop();
        for (auto& e: v->adjacent) {
            shared_ptr<Vertex> w {e.destination};
            if (w->costs == INF) {
                w->costs = v->costs + 1;
                w->previous = v;
                q.push(w);
            }
        }
    }
}

void Graph::dijkstra(const string& start_name) {
    reset();
    shared_ptr<Vertex> start {find_vertex(start_name)};
    start->costs = 0;
    auto ptr_vector_greater {[](auto* p, auto* q) { 
            return p->costs > q->costs; 
        }
    };
    priority_queue<shared_ptr<Vertex>, vector<shared_ptr<Vertex>>, decltype(ptr_vector_greater)> pq {ptr_vector_greater};
    pq.push(start);
    while (!pq.empty()) {
        shared_ptr<Vertex> v {pq.top()};
        pq.pop();
        if (!v->is_processed) {
            v->is_processed = true;
            for (auto& e: v->adjacent) {
                shared_ptr<Vertex> w {e.destination};
                int cvw {e.costs};
                if (cvw < 0) {
                    throw runtime_error {"Graph has negative edges"};
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

void Graph::negative(const string& start_name) {
    reset();
    shared_ptr<Vertex> start {find_vertex(start_name)};
    start->costs = 0;
    queue<shared_ptr<Vertex>> q;
    q.push(start);
    start->is_on_queue = true;
    start->times_queued += 1;
    while (!q.empty()) {
        shared_ptr<Vertex> v {q.front()};
        q.pop();
        v->is_on_queue = false;
        if (v->times_queued > vertices.size()) {
            throw runtime_error {"Negative cycle detected"};
        }
        for (auto& e: v->adjacent) {
            shared_ptr<Vertex> w {e.destination};
            int cvw {e.costs};
            if (w->costs > v->costs + cvw) {
                w->costs = v->costs + cvw;
                w->previous = v;
                w->times_queued += 1;
                if (!w->is_on_queue) {
                    w->is_on_queue = true;
                    q.push(w);
                }
            }
        }
    }
}

void Graph::acyclic(const string& start_name) {
    reset();
    shared_ptr<Vertex> start {find_vertex(start_name)};
    start->costs = 0;
    queue<shared_ptr<Vertex>> q;
    // calculate all indegrees
    for (auto& p: vertices) {
        for (auto&e : p.second->adjacent) {
            e.destination->indegree += 1;
        }
    }
    // start with vertices with indegree 0
    for (auto& p: vertices) {
        shared_ptr<Vertex> v = p.second;
        if (v->indegree == 0) {
            q.push(v);
        }
    }
    // for all vertices in queue
    decltype(vertices.size()) iterations {0};
    while (!q.empty()) {
        shared_ptr<Vertex> v {q.front()};
        q.pop();
        for (auto& e: v->adjacent)  {
            shared_ptr<Vertex> w {e.destination};
            int cvw {e.costs};
            w->indegree -= 1;
            if (w->indegree == 0) {
                q.push(w);
            }
            if (v->costs != INF && w->costs > v->costs + cvw) {
                w->costs = v->costs + cvw;
                w->previous = v;
            }
        }
        ++iterations;
    }
    if (iterations != vertices.size()) {
        throw runtime_error {"Graph has a cycle!"};
    }
}

int main() {
    constexpr int pasen{0};
    constexpr int pinksteren{1};
    try {
        while (pasen != pinksteren) {
            string file_name;
            do {
                println("p = positive (graph_positive.png),");
                println("n = negative (graph_negative.png),");
                println("a = acyclic  (graph_acyclic.png),");
                println("s = steden (acyclic) (graph_steden.png) or");
                println("q = quit.");
                print("Choose graph: ");
                char c;
                cin >> c; cin.get();
                switch (c) {
                    case 'p':
                    case 'P': file_name = "graph_positive.txt"; break;
                    case 'n':
                    case 'N': file_name = "graph_negative.txt"; break;
                    case 'a':
                    case 'A': file_name = "graph_acyclic.txt"; break;
                    case 's':
                    case 'S': file_name = "graph_steden.txt"; break;
                    case 'q':
                    case 'Q': return 0;
                    default: println("Wrong input, try again.");
                }
            } while (file_name.empty());
            char c;
            do {
                print("Show graph? (y/n): ");
                cin >> c; cin.get();
            } while (c != 'y' && c != 'n');
            if (c == 'y') {
                string base_name {file_name.substr(0, file_name.find(".txt"))};
                system(("start https://bitbucket.org/HR_ELEKTRO/cppprog/wiki/" + base_name + ".png").c_str());
            }
            ifstream in_file {file_name};
            if (!in_file) {
                throw runtime_error {"Cannot open " + file_name};
            }
            Graph g;
            print("Reading file ");
            string one_line;
            while (getline(in_file, one_line)) {
                string source, dest;
                int cost;
                istringstream st {one_line};
                if (st >> source >> dest >> cost) {
                    g.add_edge(source, dest, cost);
                    print(".");
                }
                else {
                    println(cerr, "Bad line: {}", one_line);
                }
            }
            print("\nEnter start node: ");
            string start_name;
            cin >> start_name; cin.get();
            print("Enter destination node: ");
            string dest_name;
            cin >> dest_name; cin.get();
            print("Enter algorithm u = unweighted, d = dijkstra, n = negative or a = acyclic: ");
            char alg;
            cin >> alg; cin.get();
            try {
                switch (alg) {
                case 'u':
                case 'U': g.unweighted(start_name); break;
                case 'd':
                case 'D': g.dijkstra(start_name); break;
                case 'n':
                case 'N': g.negative(start_name); break;
                case 'a':
                case 'A': g.acyclic(start_name); break;
                case 'q':
                case 'Q': return false;
                default: throw runtime_error {"Wrong input, try again."};
                }
                g.print_path(dest_name);
            }
            catch (const runtime_error& e) {
                println(cerr, "{}", e.what());
            }
        }
    }
    catch (const runtime_error& e) {
        println(cerr, "{}", e.what());
        return 1;
    }
}

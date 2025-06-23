#include "Grafo.h"
#include <iostream>
#include <vector>
#include <queue>      // priority_queue
#include <set>        // set
#include <tuple>      // tie / tuple
#include <functional> // greater

using namespace std;

Grafo::Grafo() {
}

Grafo::~Grafo() {
}

vector<char> Grafo::fecho_transitivo_direto(char id_no) {
    cout<<"Metodo nao implementado"<<endl;
    return {};
}

vector<char> Grafo::fecho_transitivo_indireto(char id_no) {
    cout<<"Metodo nao implementado"<<endl;
    return {};
}

vector<char> Grafo::caminho_minimo_dijkstra(char id_no_a, char id_no_b) {
    cout<<"Metodo nao implementado"<<endl;
    return {};
}

vector<char> Grafo::caminho_minimo_floyd(char id_no, char id_no_b) {
    cout<<"Metodo nao implementado"<<endl;
    return {};
}

void Grafo::adicionarAresta(char u, char v, int peso)
{
    // Procura os nós u e v na lista_adj
    No* no_u = nullptr;
    No* no_v = nullptr;
    for (No* n : lista_adj) {
        if (n->id == u) no_u = n;
        if (n->id == v) no_v = n;
    }
    if (!no_u || !no_v) return;

    // Cria as arestas
    Aresta* aresta_uv = new Aresta();
    aresta_uv->id_no_alvo = v;
    aresta_uv->peso = peso;
    no_u->arestas.push_back(aresta_uv);

    Aresta* aresta_vu = new Aresta();
    aresta_vu->id_no_alvo = u;
    aresta_vu->peso = peso;
    no_v->arestas.push_back(aresta_vu);
}

Grafo * Grafo::arvore_geradora_minima_prim(vector<char> ids_nos) {
    if (ids_nos.empty()) {
        cout << "Lista de nós vazia.\n";
        return nullptr;
    }

    // ───────────────────────── novo grafo resultado ─────────────────────────
    Grafo* agm = new Grafo();
    agm->in_direcionado       = false;
    agm->in_ponderado_aresta  = in_ponderado_aresta;
    agm->in_ponderado_vertice = in_ponderado_vertice;

    // ───────────────────────── conjunto de visitados ────────────────────────
    set<char> visitado;

    // cria os nós (vazios) no grafo resultado
    for (char id : ids_nos) {
        No* n = new No();
        n->id = id;
        agm->lista_adj.push_back(n);
    }

    // ───── min-heap: (peso, origem, destino) ─────
    typedef tuple<int, char, char> HeapEdge;
    priority_queue<HeapEdge, vector<HeapEdge>, greater<HeapEdge>> fila;

    // nó inicial
    char inicio = ids_nos.front();
    visitado.insert(inicio);

    // ponteiro para o nó inicial no grafo original
    No* no_inicio = nullptr;
    for (No* n : lista_adj)
        if (n->id == inicio) { no_inicio = n; break; }

    if (!no_inicio) {
        cout << "Nó inicial não encontrado.\n";
        delete agm;
        return nullptr;
    }

    // empilha arestas que saem do nó inicial
    for (Aresta* a : no_inicio->arestas)
        if (a) fila.emplace(a->peso, no_inicio->id, a->id_no_alvo);

    // ───────────────────────── laço principal de Prim ───────────────────────
    while (!fila.empty() && visitado.size() < ids_nos.size()) {

        // desempilha menor aresta
        int  peso; char u, v;
        tie(peso, u, v) = fila.top();
        fila.pop();

        if (visitado.count(v)) continue;   // destino já na árvore

        agm->adicionarAresta(u, v, peso);
        visitado.insert(v);

        // acha ponteiro para o nó v no grafo original
        No* no_v = nullptr;
        for (No* n : lista_adj)
            if (n->id == v) { no_v = n; break; }

        if (!no_v) continue;

        // empilha arestas que saem de v
        for (Aresta* a : no_v->arestas)
            if (a && !visitado.count(a->id_no_alvo))
                fila.emplace(a->peso, v, a->id_no_alvo);
    }

    // grafo era desconexo?
    if (visitado.size() != ids_nos.size()) {
        delete agm;
        return nullptr;
    }

    return agm;

}



Grafo * Grafo::arvore_geradora_minima_kruskal(vector<char> ids_nos) {
    cout<<"Metodo nao implementado"<<endl;
    return nullptr;
}

Grafo * Grafo::arvore_caminhamento_profundidade(char id_no) {
    cout<<"Metodo nao implementado"<<endl;
    return nullptr;
}

int Grafo::raio() {
    cout<<"Metodo nao implementado"<<endl;
    return 0;
}

int Grafo::diametro() {
    cout<<"Metodo nao implementado"<<endl;
    return 0;
}

vector<char> Grafo::centro() {
    cout<<"Metodo nao implementado"<<endl;
    return {};
}

vector<char> Grafo::periferia() {
    cout<<"Metodo nao implementado"<<endl;
    return {};
}

vector<char> Grafo::vertices_de_articulacao() {
    cout<<"Metodo nao implementado"<<endl;
    return {};
}

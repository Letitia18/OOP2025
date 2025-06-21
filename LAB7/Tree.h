#pragma once
#include <iostream>

template <typename T>
struct Node {
    T info;
    Node** children;
    unsigned int nrChildren;
    unsigned int capacity; 

    Node() : children(nullptr), nrChildren(0), capacity(0) {}
};

template <typename T>
class Tree {
public:
    Node<T>* root;

    Tree() : root(nullptr) {}

    Node<T>* create_node(const T& info) {
        Node<T>* node = new Node<T>;
        node->info = info;
        node->nrChildren = 0;
        node->capacity = 10; 
        node->children = new Node<T>*[node->capacity];
        return node;
    }

    void add_node(Node<T>* parent, const T& info) {
        if (parent == nullptr) {
            if (root != nullptr) {
                std::cerr << "Root already exists\n";
                return;
            }
            root = create_node(info);
            std::cout << "Added root node: " << root->info << "\n";
        }
        else {
            if (parent->nrChildren == parent->capacity) {
                unsigned int newCap = parent->capacity * 2;
                Node<T>** newChildren = new Node<T>*[newCap];
                for (unsigned int i = 0; i < parent->nrChildren; ++i)
                    newChildren[i] = parent->children[i];
                delete[] parent->children;
                parent->children = newChildren;
                parent->capacity = newCap;
            }
            parent->children[parent->nrChildren++] = create_node(info);
            std::cout << "Added node " << info << " to parent " << parent->info << "\n";
        }
    }

    Node<T>* get_node(Node<T>* parent, unsigned int index) {
        if (parent == nullptr || index >= parent->nrChildren)
            return nullptr;
        return parent->children[index];
    }

    void delete_rec(Node<T>* node) {
        if (!node) return;
        for (unsigned int i = 0; i < node->nrChildren; ++i) {
            delete_rec(node->children[i]);
        }
        delete[] node->children;
        delete node;
    }

    void delete_node(Node<T>* parent, Node<T>* nodeToDelete) {
        if (parent == nullptr || nodeToDelete == nullptr) return;

        unsigned int idx = parent->nrChildren;
        for (unsigned int i = 0; i < parent->nrChildren; ++i) {
            if (parent->children[i] == nodeToDelete) {
                idx = i;
                break;
            }
        }
        if (idx == parent->nrChildren) return; 

        delete_rec(nodeToDelete);

        for (unsigned int i = idx; i < parent->nrChildren - 1; ++i) {
            parent->children[i] = parent->children[i + 1];
        }
        parent->nrChildren--;
    }

    Node<T>* find(Node<T>* node, const T& param, bool (*cmp)(const T&, const T&)) {
        if (node == nullptr) return nullptr;
        if (cmp(node->info, param)) return node;
        for (unsigned int i = 0; i < node->nrChildren; ++i) {
            Node<T>* found = find(node->children[i], param, cmp);
            if (found != nullptr)
                return found;
        }
        return nullptr;
    }

    void insert(Node<T>* parent, unsigned int index, Node<T>* newNode) {
        if (parent == nullptr || newNode == nullptr) return;
        if (index > parent->nrChildren) index = parent->nrChildren;

        if (parent->nrChildren == parent->capacity) {
            unsigned int newCap = parent->capacity * 2;
            Node<T>** newChildren = new Node<T>*[newCap];
            for (unsigned int i = 0; i < parent->nrChildren; ++i)
                newChildren[i] = parent->children[i];
            delete[] parent->children;
            parent->children = newChildren;
            parent->capacity = newCap;
        }

        for (unsigned int i = parent->nrChildren; i > index; --i)
            parent->children[i] = parent->children[i - 1];

        parent->children[index] = newNode;
        parent->nrChildren++;
    }

    void sort(Node<T>* parent, int (*compare)(T, T) = nullptr) {
        if (parent == nullptr) return;
        if (compare == nullptr) {
            for (unsigned int i = 0; i < parent->nrChildren - 1; ++i) {
                for (unsigned int j = i + 1; j < parent->nrChildren; ++j) {
                    if (parent->children[j]->info < parent->children[i]->info) {
                        std::swap(parent->children[i]->info, parent->children[j]->info);
                    }
                }
            }
        }
        else {
            for (unsigned int i = 0; i < parent->nrChildren - 1; ++i) {
                for (unsigned int j = i + 1; j < parent->nrChildren; ++j) {
                    if (compare(parent->children[i]->info, parent->children[j]->info) > 0) {
                        std::swap(parent->children[i]->info, parent->children[j]->info);
                    }
                }
            }
        }
    }

    int count(Node<T>* node) {
        if (node == nullptr) return 0;
        int cnt = 1; 
        for (unsigned int i = 0; i < node->nrChildren; ++i) {
            cnt += count(node->children[i]);
        }
        return cnt;
    }

    void printTree(Node<T>* node, const std::string& prefix = "", bool isLast = true) {
        if (node == nullptr) return;
        std::cout << prefix;
        std::cout << (isLast ? "'-- " : "|-- ");
        std::cout << node->info << std::endl;
        for (unsigned int i = 0; i < node->nrChildren; ++i) {
            printTree(node->children[i], prefix + (isLast ? "    " : "|   "), i == node->nrChildren - 1);
        }
    }
};

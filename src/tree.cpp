#include "../include/tree.h"
#include <iostream>

TreePoli::TreePoli() : root(nullptr) {}

TreePoli::~TreePoli() {
    hapusRekursif(root);
}

TreeNode* TreePoli::buatNode(const std::string& nama) {
    TreeNode* node = new TreeNode;
    node->nama = nama;
    node->child = nullptr;
    node->sibling = nullptr;
    return node;
}

void TreePoli::inisialisasi() {
    root = buatNode("Klinik E-Health");

    TreeNode* poliUmum = buatNode("Poli Umum");
    TreeNode* poliGigi = buatNode("Poli Gigi");
    TreeNode* poliAnak = buatNode("Poli Anak");
    TreeNode* poliDalam = buatNode("Poli Penyakit Dalam");

    root->child = poliUmum;
    poliUmum->sibling = poliGigi;
    poliGigi->sibling = poliAnak;
    poliAnak->sibling = poliDalam;
}

void TreePoli::tampilkanRekursif(TreeNode* node, int level) const {
    if (node == nullptr) return;

    for (int i = 0; i < level; i++)
        std::cout << "  ";

    if (level == 0)
        std::cout << node->nama << "\n";
    else
        std::cout << "- " << node->nama << "\n";

    tampilkanRekursif(node->child, level + 1);

    if (level > 0)
        tampilkanRekursif(node->sibling, level);
    else
        tampilkanRekursif(node->child ? node->child->sibling : nullptr, level + 1);
}

void TreePoli::tampilkan() const {
    if (root == nullptr) {
        std::cout << "  [Tree belum diinisialisasi]\n";
        return;
    }

    std::cout << "  " << root->nama << "\n";
    TreeNode* child = root->child;
    while (child != nullptr) {
        std::cout << "    - " << child->nama << "\n";
        child = child->sibling;
    }
}

bool TreePoli::cariRekursif(TreeNode* node, const std::string& namaPoli) const {
    if (node == nullptr) return false;
    if (node->nama.find(namaPoli) != std::string::npos) return true;

    if (cariRekursif(node->child, namaPoli)) return true;
    return cariRekursif(node->sibling, namaPoli);
}

bool TreePoli::cariPoli(const std::string& namaPoli) const {
    return cariRekursif(root, namaPoli);
}

void TreePoli::hapusRekursif(TreeNode* node) {
    if (node == nullptr) return;
    hapusRekursif(node->sibling);
    hapusRekursif(node->child);
    delete node;
}

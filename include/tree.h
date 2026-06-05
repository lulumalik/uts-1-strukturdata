#ifndef TREE_H
#define TREE_H

#include <string>

// Tree: struktur hierarki poli klinik e-health
struct TreeNode {
    std::string nama;
    TreeNode* child;
    TreeNode* sibling;
};

class TreePoli {
private:
    TreeNode* root;

    TreeNode* buatNode(const std::string& nama);
    // fungsi untuk menampilkan data pasien di tree
    void tampilkanRekursif(TreeNode* node, int level) const;
    // fungsi untuk menghapus data pasien dari tree
    void hapusRekursif(TreeNode* node);

public:
    TreePoli();
    ~TreePoli();

    // fungsi untuk menginisialisasi tree
    void inisialisasi();
    // fungsi untuk menampilkan data pasien di tree
    void tampilkan() const;
    // fungsi untuk mencari data pasien di tree
    bool cariPoli(const std::string& namaPoli) const;
    // fungsi untuk mencari data pasien di tree secara rekursif
    bool cariRekursif(TreeNode* node, const std::string& namaPoli) const;
};

#endif

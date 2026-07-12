# Dokumentasi Project
## Sistem Manajemen Antrian & Rekam Medis Pasien Berbasis E-Health

**Mata Kuliah:** Struktur Data dan Algoritma  
**Studi Kasus:** Simulasi sistem klinik e-health dengan kapasitas maksimal 150 pasien per bulan  

**Anggota Kelompok:**
- LULU MAULANA MALIK (250401010517)
- A. M. NABIL AIENDRA DZIKRA (250401010507)
- MUHAMMAD FARIS (250401010509)

---

## Kata Pengantar

Puji syukur kami panjatkan ke hadirat Allah SWT, karena atas rahmat dan karunia-Nya, kami dapat menyelesaikan dokumentasi project **Sistem Manajemen Antrian & Rekam Medis Pasien Berbasis E-Health** ini sebagai bagian dari penyelesaian Ujian Tengah Semester mata kuliah **Struktur Data dan Algoritma**.

Dokumentasi ini disusun untuk menjelaskan latar belakang, perancangan, dan implementasi sistem simulasi klinik e-health yang dibangun menggunakan bahasa pemrograman C++. Melalui studi kasus pengelolaan data pasien, antrian pelayanan, riwayat pemeriksaan medis, jaringan rujukan antar poli, serta algoritma sorting dan searching, kami berupaya menerapkan berbagai konsep struktur data dan algoritma — Array, Linked List, Queue, Stack, Tree, Graph, BFS, DFS, Sorting, dan Big O — dalam konteks yang relevan dengan kebutuhan nyata di bidang kesehatan digital.

Penyusunan dokumentasi ini tidak lepas dari bimbingan dan arahan dosen pengampu mata kuliah Struktur Data dan Algoritma. Atas ilmu dan wawasannya, kami ucapkan terima kasih yang sebesar-besarnya. Kami juga menyadari bahwa dokumentasi ini masih jauh dari sempurna. Oleh karena itu, kritik dan saran yang membangun dari dosen maupun rekan sejawat sangat kami harapkan demi perbaikan di masa mendatang.

Semoga dokumentasi ini dapat bermanfaat sebagai referensi pembelajaran penerapan struktur data dan algoritma, serta menjadi landasan bagi pengembangan sistem serupa di kemudian hari.

Malang, Juni 2026

Penyusun,

1. LULU MAULANA MALIK (250401010517)  
2. A. M. NABIL AIENDRA DZIKRA (250401010507)  
3. MUHAMMAD FARIS (250401010509)

---

## 1. Pendahuluan

Perkembangan teknologi informasi di sektor kesehatan mendorong munculnya sistem **e-health** yang membantu pengelolaan data pasien, antrian pelayanan, dan riwayat pemeriksaan medis secara lebih terstruktur. Di klinik, petugas medis dan administrasi membutuhkan sistem yang mampu menyimpan data pasien, mengatur antrian pelayanan, serta mencatat riwayat pemeriksaan dengan cepat dan terorganisir.

Project ini mengimplementasikan simulasi **Sistem Manajemen Antrian & Rekam Medis Pasien Berbasis E-Health** menggunakan bahasa pemrograman **C++**. Sistem dibangun tanpa database eksternal, melainkan menggunakan berbagai **struktur data** dasar — Array, Linked List, Queue, Stack, Tree, dan Graph — serta algoritma **BFS, DFS, Sorting, dan Searching** sebagai media pengelolaan data secara in-memory selama program berjalan.

Melalui studi kasus klinik dengan kapasitas maksimal **150 pasien per bulan**, project ini dirancang untuk mendemonstrasikan penerapan konsep struktur data dan algoritma dalam konteks nyata pengelolaan data pasien, antrian, riwayat medis, dan rujukan antar unit layanan di fasilitas kesehatan.

---

## 2. Rumusan Masalah

Berdasarkan studi kasus klinik e-health, permasalahan yang ingin diselesaikan adalah:

1. **Pengelolaan data pasien belum terstruktur** — Data pasien seperti nomor rekam medis, nama, umur, poli tujuan, dan status pemeriksaan perlu disimpan dan diakses secara efisien tanpa database eksternal.
2. **Antrian pelayanan tidak terkelola dengan baik** — Pasien yang menunggu pemeriksaan membutuhkan mekanisme antrian berurutan (first-in, first-out) agar pelayanan berjalan adil dan teratur.
3. **Riwayat pemeriksaan medis sulit dilacak** — Setelah pasien dilayani, data pemeriksaan perlu dicatat agar dapat dilihat kembali, terutama riwayat terbaru.
4. **Struktur poli klinik belum direpresentasikan secara hierarkis** — Klinik memiliki beberapa poli (Umum, Gigi, Anak, Penyakit Dalam) yang perlu dimodelkan agar validasi data pasien sesuai dengan layanan yang tersedia.
5. **Operasi CRUD pasien rentan terhadap kesalahan input** — Penambahan, pencarian, pembaruan, dan penghapusan data pasien harus dilengkapi validasi untuk mencegah data kosong, duplikasi, dan input poli yang tidak valid.
6. **Jalur rujukan antar unit layanan belum dimodelkan** — Pasien sering dirujuk antar poli, lab, atau apotek; perlu graph agar jalur rujukan dapat ditelusuri dengan BFS dan DFS.
7. **Daftar pasien belum terurut dan pencarian belum dianalisis** — Petugas membutuhkan sorting data pasien serta perbandingan efisiensi pencarian (linear vs binary) berdasarkan notasi Big O.

---

## 3. Tujuan Penelitian

Tujuan dari project ini adalah:

1. **Merancang dan mengimplementasikan** sistem manajemen antrian dan rekam medis pasien berbasis e-health menggunakan C++.
2. **Menerapkan lima struktur data** — Array, Linked List, Queue, Stack, dan Tree — sesuai fungsinya masing-masing dalam konteks klinik.
3. **Membangun modul CRUD data pasien** (Create, Read, Update, Delete) dengan validasi data yang memadai.
4. **Mengimplementasikan sistem antrian pasien** berbasis Queue (FIFO) dan **riwayat medis** berbasis Stack (LIFO).
5. **Mendemonstrasikan penggunaan Tree** untuk merepresentasikan hierarki poli klinik dan validasi input poli pasien.
6. **Mengimplementasikan Graph** jaringan rujukan poli beserta **BFS** (jalur terpendek) dan **DFS** (cek keterhubungan).
7. **Mengimplementasikan algoritma sorting** (Bubble, Selection, Insertion) dan **searching** (Linear & Binary) disertai analisis **Big O**.
8. **Menyediakan antarmuka berbasis menu** (CLI) yang memudahkan simulasi operasional klinik e-health.

---

## 4. Batasan Masalah

Agar ruang lingkup project tetap fokus, batasan yang ditetapkan adalah:

| No | Batasan |
|----|---------|
| 1 | Sistem berjalan sebagai **aplikasi console (CLI)**, bukan aplikasi web atau mobile. |
| 2 | Data disimpan **in-memory** selama program berjalan; tidak ada penyimpanan permanen (file/database). |
| 3 | Kapasitas maksimal pasien dibatasi **150 pasien per bulan** (`MAX_PASIEN = 150`). |
| 4 | Poli klinik yang tersedia hanya **4 poli**: Umum, Gigi, Anak, dan Penyakit Dalam. |
| 5 | Tidak ada fitur autentikasi/login pengguna (admin, dokter, atau petugas). |
| 6 | Tidak ada integrasi dengan perangkat medis, jaringan, atau layanan cloud. |
| 7 | Status pasien terbatas pada tiga nilai: **Menunggu**, **Diperiksa**, dan **Selesai**. |
| 8 | Nomor rekam medis (`noRM`) bersifat **unik** sebagai primary key data pasien. |

---

## 5. Manfaat Penelitian

Manfaat yang diharapkan dari project ini:

**Manfaat Teoritis:**
- Memperdalam pemahaman mahasiswa tentang implementasi struktur data (Array, Linked List, Queue, Stack, Tree, Graph) dan algoritma (BFS, DFS, Sorting, Searching, Big O) dalam kasus nyata.
- Menunjukkan hubungan antara konsep teori struktur data dengan kebutuhan praktis di bidang kesehatan digital.

**Manfaat Praktis:**
- Menyediakan prototype sederhana sistem klinik e-health yang dapat dikembangkan lebih lanjut.
- Mempermudah simulasi alur antrian pasien, pencatatan riwayat medis, dan perencanaan rujukan antar unit layanan.
- Membantu petugas mengurutkan daftar pasien dan membandingkan efisiensi pencarian No RM.
- Menjadi referensi implementasi CRUD, graph traversal, sorting/searching, dan error handling.

**Manfaat Akademik:**
- Memenuhi tugas UTS mata kuliah Struktur Data dan Algoritma.
- Dokumentasi project dapat digunakan sebagai bahan laporan dan presentasi kelompok.

---

## 6. Landasan Teori

### 6.1 Struktur Data yang Digunakan

| Struktur Data | Kelas | Fungsi dalam Sistem |
|---------------|-------|---------------------|
| **Array** | `ArrayPasien` | Penyimpanan data pasien dengan akses indeks O(1); kapasitas tetap 150 elemen; target sorting & binary search. |
| **Linked List** | `LinkedListPasien` | Penyimpanan dinamis data pasien; insert di head; pencarian sequential. |
| **Queue (FIFO)** | `QueueAntrian` | Antrian pasien yang menunggu dilayani; enqueue saat masuk antrian, dequeue saat dilayani. |
| **Stack (LIFO)** | `StackRiwayat` | Riwayat pemeriksaan medis; push saat pasien selesai dilayani, pop untuk mengambil riwayat terbaru. |
| **Tree** | `TreePoli` | Hierarki poli klinik; validasi poli tujuan pasien menggunakan pencarian rekursif. |
| **Graph** | `GraphRujukan` | Jaringan rujukan antar unit (Umum, Gigi, Anak, Penyakit Dalam, Lab, Apotek); ditelusuri dengan BFS & DFS. |

### 6.2 Fungsi-Fungsi yang Digunakan

#### A. Struktur Data Pasien (`types.h`)

| Komponen | Keterangan |
|----------|------------|
| `struct Pasien` | Representasi data pasien |
| `MAX_PASIEN` | Konstanta kapasitas maksimal = 150 |

**Atribut `Pasien`:**

| Field | Tipe | Keterangan |
|-------|------|------------|
| `noRM` | `string` | Nomor rekam medis (primary key, unik) |
| `nama` | `string` | Nama lengkap pasien |
| `umur` | `int` | Usia pasien |
| `poli` | `string` | Poli tujuan (Umum, Gigi, Anak, Penyakit Dalam) |
| `status` | `string` | Status pemeriksaan (Menunggu, Diperiksa, Selesai) |

---

#### B. Array — `ArrayPasien` (`array.h`, `array.cpp`)

| Fungsi | Return | Deskripsi |
|--------|--------|-----------|
| `ArrayPasien()` | — | Konstruktor; inisialisasi `jumlah = 0` |
| `tambah(p)` | `bool` | Menambah pasien ke array; gagal jika penuh |
| `cari(noRM, hasil)` | `bool` | Mencari pasien berdasarkan No RM (linear search) |
| `update(noRM, pBaru)` | `bool` | Memperbarui data pasien berdasarkan No RM |
| `hapus(noRM)` | `bool` | Menghapus pasien dan menggeser elemen array |
| `tampilkan()` | `void` | Menampilkan seluruh data pasien dalam array |
| `getJumlah()` | `int` | Mengembalikan jumlah pasien saat ini |
| `duplikat(noRM)` | `bool` | Mengecek apakah No RM sudah terdaftar |

**Kompleksitas:** Akses indeks O(1); pencarian, update, hapus O(n).

---

#### C. Linked List — `LinkedListPasien` (`linkedlist.h`, `linkedlist.cpp`)

| Fungsi | Return | Deskripsi |
|--------|--------|-----------|
| `LinkedListPasien()` | — | Konstruktor; `head = nullptr` |
| `~LinkedListPasien()` | — | Destruktor; dealokasi semua node |
| `tambah(p)` | `void` | Insert node baru di head (prepend) |
| `cari(noRM)` | `Node*` | Sequential search; mengembalikan pointer node |
| `update(noRM, pBaru)` | `bool` | Update data pada node yang ditemukan |
| `hapus(noRM)` | `bool` | Hapus node dengan manipulasi pointer `prev` dan `next` |
| `tampilkan()` | `void` | Traversal dan tampilkan semua pasien |
| `hitung()` | `int` | Menghitung jumlah node |
| `duplikat(noRM)` | `bool` | Mengecek duplikasi No RM |

**Struktur Node:**
```cpp
struct Node {
    Pasien data;
    Node* next;
};
```

---

#### D. Queue — `QueueAntrian` (`queue.h`, `queue.cpp`)

| Fungsi | Return | Deskripsi |
|--------|--------|-----------|
| `QueueAntrian()` | — | Konstruktor; `front = 0`, `rear = 0` |
| `enqueue(p)` | `bool` | Menambah pasien ke antrian (belakang) |
| `dequeue(p)` | `bool` | Mengeluarkan pasien dari antrian (depan) |
| `tampilkan()` | `void` | Menampilkan urutan antrian |
| `kosong()` | `bool` | Mengecek apakah antrian kosong |
| `penuh()` | `bool` | Mengecek apakah antrian penuh |
| `ukuran()` | `int` | Jumlah pasien dalam antrian |

**Prinsip:** First In, First Out (FIFO) — pasien yang lebih dulu masuk antrian dilayani terlebih dahulu.

---

#### E. Stack — `StackRiwayat` (`stack.h`, `stack.cpp`)

| Fungsi | Return | Deskripsi |
|--------|--------|-----------|
| `StackRiwayat()` | — | Konstruktor; `top = -1` |
| `push(p)` | `bool` | Menyimpan riwayat pemeriksaan pasien |
| `pop(p)` | `bool` | Mengambil riwayat pemeriksaan terbaru |
| `tampilkan()` | `void` | Menampilkan riwayat dari terbaru ke terlama |
| `kosong()` | `bool` | Mengecek apakah stack kosong |
| `penuh()` | `bool` | Mengecek apakah stack penuh |
| `ukuran()` | `int` | Jumlah data riwayat |

**Prinsip:** Last In, First Out (LIFO) — riwayat terakhir yang dicatat menjadi yang pertama diakses saat pop.

---

#### F. Tree — `TreePoli` (`tree.h`, `tree.cpp`)

| Fungsi | Return | Deskripsi |
|--------|--------|-----------|
| `TreePoli()` | — | Konstruktor; `root = nullptr` |
| `~TreePoli()` | — | Destruktor; dealokasi tree secara rekursif |
| `inisialisasi()` | `void` | Membangun tree poli klinik |
| `tampilkan()` | `void` | Menampilkan hierarki poli |
| `cariPoli(namaPoli)` | `bool` | Validasi apakah poli tersedia |
| `cariRekursif(node, namaPoli)` | `bool` | Pencarian poli secara rekursif (child & sibling) |
| `buatNode(nama)` | `TreeNode*` | Membuat node tree baru (private) |
| `tampilkanRekursif(node, level)` | `void` | Traversal tree (private) |
| `hapusRekursif(node)` | `void` | Dealokasi node tree (private) |

**Struktur Tree Poli:**
```
Klinik E-Health
  ├── Poli Umum
  ├── Poli Gigi
  ├── Poli Anak
  └── Poli Penyakit Dalam
```

**Struktur Node:**
```cpp
struct TreeNode {
    string nama;
    TreeNode* child;    // anak pertama
    TreeNode* sibling;  // saudara sejajar
};
```

---

#### G. Graph — `GraphRujukan` (`graph.h`, `graph.cpp`)

Graph merepresentasikan **jaringan rujukan** antar unit layanan klinik. Vertex = unit (Umum, Gigi, Anak, Penyakit Dalam, Lab, Apotek). Edge = arah rujukan yang diizinkan.

| Fungsi | Return | Deskripsi |
|--------|--------|-----------|
| `inisialisasi()` | `void` | Membangun vertex & edge rujukan default |
| `tampilkan()` | `void` | Menampilkan vertex dan edge |
| `bfs(mulai)` | `void` | Traversal BFS dari poli awal — O(V+E) |
| `dfs(mulai)` | `void` | Traversal DFS dari poli awal — O(V+E) |
| `jalurTerpendek(asal, tujuan)` | `void` | BFS + rekonstruksi parent → jalur rujukan terpendek |
| `adaJalur(asal, tujuan)` | `bool` | DFS iteratif (stack) untuk cek keterhubungan |
| `getJumlahVertex()` | `int` | Jumlah vertex graph |

**Manfaat e-health:** petugas dapat melihat rute rujukan yang paling pendek (BFS) dan memastikan apakah rujukan dari poli A ke B memungkinkan (DFS).

**Contoh jaringan:**
```
Umum → Gigi, Anak, Penyakit Dalam, Lab, Apotek
Gigi → Umum, Apotek
Anak → Umum, Penyakit Dalam, Lab, Apotek
Penyakit Dalam → Umum, Lab, Apotek
Lab → Umum, Apotek
```

---

#### H. Sorting & Searching (`sortsearch.h`, `sortsearch.cpp`)

| Fungsi | Big O | Deskripsi |
|--------|-------|-----------|
| `bubbleSort(arr, kriteria)` | O(n²) | Urutkan pasien (No RM / Nama / Umur) |
| `selectionSort(arr, kriteria)` | O(n²) | Urutkan dengan pemilihan elemen minimum |
| `insertionSort(arr, kriteria)` | O(n²) / best O(n) | Sisipkan elemen ke posisi yang tepat |
| `linearSearch(arr, noRM, ...)` | O(n) | Cari No RM dari awal ke akhir |
| `binarySearch(arr, noRM, ...)` | O(log n) | Cari No RM pada data terurut |
| `bandingkanPencarian(...)` | — | Bandingkan jumlah perbandingan Linear vs Binary |
| `tampilkanAnalisisBigO()` | — | Ringkasan kompleksitas seluruh sistem |

**Manfaat e-health:** daftar pasien dapat ditampilkan terurut; binary search mempercepat pencarian No RM pada data besar setelah sorting.

---

#### I. Fungsi Utama Program (`main.cpp`)

| Fungsi | Deskripsi |
|--------|-----------|
| `bersihkanBuffer()` | Membersihkan buffer input setelah `cin >>` |
| `tampilkanMenu()` | Menampilkan menu utama sistem |
| `inputPasien()` | Mengambil input data pasien dari pengguna |
| `tambahPasien()` | Alur penambahan data pasien + validasi |
| `cariPasien()` | Alur pencarian data pasien |
| `updatePasien()` | Alur pembaruan data pasien |
| `hapusPasien()` | Alur penghapusan data pasien |
| `kelolaAntrian()` | Submenu antrian: enqueue, dequeue, tampilkan |
| `riwayatMedis()` | Submenu riwayat: tampilkan, pop |
| `statistikPasien()` | Menampilkan ringkasan statistik sistem |
| `kelolaGraphRujukan()` | Submenu Graph: BFS, DFS, jalur terpendek |
| `kelolaSorting()` | Submenu Sorting: Bubble, Selection, Insertion |
| `kelolaSearchingBigO()` | Submenu Searching & analisis Big O |
| `main()` | Entry point; inisialisasi tree/graph dan loop menu |

---

## 7. Analisis dan Perancangan Sistem

### 7.1 Analisis

Sistem klinik e-health yang dirancang harus mampu menangani kebutuhan operasional berikut:

1. **Manajemen data pasien** — CRUD data pasien dengan nomor rekam medis sebagai identitas unik.
2. **Pengaturan antrian** — Pasien yang terdaftar dapat dimasukkan ke antrian dan dilayani secara berurutan.
3. **Pencatatan riwayat** — Setiap pasien yang selesai dilayani dicatat ke riwayat medis.
4. **Validasi poli** — Poli tujuan pasien harus sesuai dengan layanan yang tersedia di klinik.
5. **Monitoring** — Statistik jumlah pasien, antrian, dan riwayat dapat dilihat kapan saja.
6. **Rujukan antar unit** — Jalur rujukan dimodelkan sebagai Graph dan ditelusuri dengan BFS/DFS.
7. **Pengurutan & pencarian efisien** — Data pasien dapat di-sort; efisiensi pencarian dianalisis dengan Big O.

**Analisis kebutuhan fungsional** dipetakan ke struktur data / algoritma sebagai berikut:

```
Kebutuhan Operasional          →  Struktur Data / Algoritma
────────────────────────────────────────────────────────────
Simpan & akses data pasien     →  Array + Linked List
Antrian pelayanan pasien       →  Queue (FIFO)
Riwayat pemeriksaan medis      →  Stack (LIFO)
Hierarki & validasi poli       →  Tree
Jaringan rujukan antar unit    →  Graph + BFS + DFS
Daftar pasien terurut          →  Sorting (Bubble/Selection/Insertion)
Cari No RM + analisis Big O    →  Linear Search & Binary Search
```

**Alasan penggunaan ganda Array dan Linked List:**
- **Array** digunakan untuk demonstrasi penyimpanan berindeks dengan akses O(1), kapasitas tetap, serta target sorting & binary search.
- **Linked List** digunakan untuk penyimpanan dinamis dengan insert/delete fleksibel melalui pointer.
- Keduanya disinkronkan saat operasi tambah, update, dan hapus agar data konsisten.
- Sorting mengubah urutan Array saja (Linked List tetap mengikuti urutan insert).

---

### 7.2 Kebutuhan Sistem

#### Kebutuhan Fungsional

| No | Kebutuhan | Menu | Keterangan |
|----|-----------|------|------------|
| F1 | Tambah data pasien | 1 | Validasi kosong, duplikasi, dan poli |
| F2 | Cari data pasien | 2 | Pencarian berdasarkan No RM |
| F3 | Update data pasien | 3 | Update di Linked List dan Array |
| F4 | Hapus data pasien | 4 | Hapus di Linked List dan Array |
| F5 | Tampilkan pasien (Linked List) | 5 | Traversal linked list |
| F6 | Tampilkan pasien (Array) | 6 | Iterasi array |
| F7 | Kelola antrian | 7 | Enqueue, dequeue, tampilkan antrian |
| F8 | Riwayat medis | 8 | Push (otomatis), tampilkan, pop |
| F9 | Struktur poli klinik | 9 | Tampilkan tree poli |
| F10 | Statistik pasien | 10 | Ringkasan jumlah data |
| F11 | Graph rujukan (BFS/DFS) | 11 | Jaringan & jalur rujukan |
| F12 | Sorting data pasien | 12 | Bubble / Selection / Insertion |
| F13 | Searching & Big O | 13 | Linear vs Binary + analisis |
| F14 | Keluar program | 0 | Terminasi aplikasi |

#### Kebutuhan Non-Fungsional

| No | Kebutuhan | Spesifikasi |
|----|-----------|-------------|
| NF1 | Bahasa pemrograman | C++ (standar C++17) |
| NF2 | Platform | Console/CLI (Windows & Linux) |
| NF3 | Kapasitas data | Maksimal 150 pasien |
| NF4 | Performa pencarian | Linear O(n) dan Binary O(log n) |
| NF5 | Traversal graph | BFS & DFS O(V+E) |
| NF6 | Arsitektur kode | Modular (header + source terpisah) |

#### Struktur File Project

```
uts-strukturdata/
├── include/
│   ├── types.h          # Struct Pasien & konstanta
│   ├── array.h          # Deklarasi ArrayPasien
│   ├── linkedlist.h     # Deklarasi LinkedListPasien
│   ├── queue.h          # Deklarasi QueueAntrian
│   ├── stack.h          # Deklarasi StackRiwayat
│   ├── tree.h           # Deklarasi TreePoli
│   ├── graph.h          # Deklarasi GraphRujukan (BFS/DFS)
│   └── sortsearch.h     # Sorting & Searching + Big O
├── src/
│   ├── main.cpp         # Program utama & menu
│   ├── array.cpp
│   ├── linkedlist.cpp
│   ├── queue.cpp
│   ├── stack.cpp
│   ├── tree.cpp
│   ├── graph.cpp
│   └── sortsearch.cpp
├── build.bat / build.sh
├── Makefile
├── README.md
└── DOKUMENTASI.md
```

---

### 7.3 Perancangan Struktur Data

#### Diagram Relasi Objek Global

```
main()
  │
  ├── ArrayPasien arrayPasien      [data pasien — indexed + sorting/search]
  ├── LinkedListPasien linkedList  [data pasien — dynamic list]
  ├── QueueAntrian antrian         [antrian pelayanan — FIFO]
  ├── StackRiwayat riwayat         [riwayat medis — LIFO]
  ├── TreePoli treePoli            [hierarki poli — tree]
  └── GraphRujukan graphRujukan    [jaringan rujukan — graph BFS/DFS]
```

#### Spesifikasi Tiap Struktur Data

**1. Array (`ArrayPasien`)**
- Tipe: array statis `Pasien data[MAX_PASIEN]`
- Counter: `int jumlah`
- Operasi hapus: shift elemen ke kiri
- Aksesor sorting: `getAt`, `setAt`, `tukar`
- Kegunaan: penyimpanan berindeks, tampilan, sorting, binary search

**2. Linked List (`LinkedListPasien`)**
- Tipe: singly linked list dengan insert di head
- Pointer: `Node* head`
- Operasi hapus: manipulasi `prev->next` dan `delete`
- Kegunaan: penyimpanan dinamis, pencarian utama saat CRUD

**3. Queue (`QueueAntrian`)**
- Tipe: array-based queue dengan `front` dan `rear`
- Kapasitas: `MAX_PASIEN`
- Kegunaan: antrian pasien menunggu pelayanan

**4. Stack (`StackRiwayat`)**
- Tipe: array-based stack dengan `top`
- Kapasitas: `MAX_PASIEN`
- Kegunaan: riwayat pasien yang sudah dilayani

**5. Tree (`TreePoli`)**
- Tipe: tree dengan pointer `child` dan `sibling` (left-child, right-sibling)
- Root: `"Klinik E-Health"`
- Kegunaan: validasi poli dan representasi hierarki klinik

**6. Graph (`GraphRujukan`)**
- Tipe: adjacency matrix `bool adj[MAX_VERTEX][MAX_VERTEX]`
- Vertex: Umum, Gigi, Anak, Penyakit Dalam, Lab, Apotek
- Edge: arah rujukan antar unit (directed)
- Algoritma: BFS (jalur terpendek), DFS (cek keterhubungan)
- Big O traversal: O(V + E)

**7. Sorting & Searching**
- Sorting in-place pada ArrayPasien (Bubble / Selection / Insertion)
- Kriteria: No RM, Nama, atau Umur
- Linear Search O(n) vs Binary Search O(log n) dengan hitungan perbandingan
- Binary Search mensyaratkan data sudah diurutkan berdasarkan No RM

---

### 7.4 Data Pasien

#### Definisi Entitas

Entitas **Pasien** adalah unit data utama dalam sistem. Setiap pasien direpresentasikan oleh struct `Pasien` dengan atribut:

| Atribut | Tipe | Constraint | Contoh |
|---------|------|------------|--------|
| `noRM` | string | Wajib, unik, tidak kosong | `"RM001"` |
| `nama` | string | Wajib, tidak kosong | `"Budi Santoso"` |
| `umur` | int | Wajib, bilangan bulat | `35` |
| `poli` | string | Wajib, harus valid di tree | `"Umum"` |
| `status` | string | Otomatis/manual | `"Menunggu"` |

#### Aturan Bisnis Data Pasien

1. **No RM unik** — Tidak boleh ada dua pasien dengan nomor rekam medis yang sama.
2. **Poli harus valid** — Nama poli harus cocok dengan salah satu poli di tree (`Umum`, `Gigi`, `Anak`, `Penyakit Dalam`).
3. **Kapasitas terbatas** — Maksimal 150 pasien tersimpan dalam array dan linked list.
4. **Status default** — Saat ditambahkan ke antrian, status diubah menjadi `"Menunggu"`.
5. **Status selesai** — Saat dequeue (dilayani), status diubah menjadi `"Selesai"` dan data dimasukkan ke stack riwayat.
6. **Sinkronisasi data** — Setiap operasi tambah, update, dan hapus dilakukan pada **Linked List dan Array** secara bersamaan.

#### Contoh Data Pasien

```
No RM  : RM001
Nama   : Siti Aminah
Umur   : 28 tahun
Poli   : Gigi
Status : Menunggu
```

---

### 7.5 Flow Sistem

#### Flow Program Utama

```
[START]
   │
   ▼
Inisialisasi Tree Poli
   │
   ▼
Tampilkan Struktur Poli Klinik
   │
   ▼
┌──────────────────────┐
│   Tampilkan Menu     │◄─────────────────────────┐
└──────────┬───────────┘                          │
           │                                      │
           ▼                                      │
    Input Pilihan Menu                            │
           │                                      │
     ┌─────┴──────────────────────────┐           │
     │                                │           │
  Pilihan 1-10                    Pilihan 0        │
     │                                │           │
     ▼                                ▼           │
  Proses Fitur                  [KELUAR PROGRAM]  │
     │                                            │
     └────────────────────────────────────────────┘
```

#### Flow Tambah Data Pasien (Menu 1)

```
Input data pasien (noRM, nama, umur, poli, status)
   │
   ▼
Apakah noRM/nama/poli kosong? ──[Ya]──► [ERROR] Data tidak boleh kosong
   │ [Tidak]
   ▼
Apakah noRM duplikat? ──[Ya]──► [ERROR] Duplikasi data
   │ [Tidak]
   ▼
Apakah poli valid (tree)? ──[Tidak]──► [ERROR] Poli tidak ditemukan
   │ [Ya]
   ▼
Tambah ke Linked List
   │
   ▼
Tambah ke Array ──[Gagal/Penuh]──► Rollback Linked List + [ERROR] Array penuh
   │ [Sukses]
   ▼
[SUKSES] Pasien berhasil ditambahkan
```

#### Flow Kelola Antrian (Menu 7)

**Enqueue (Masuk Antrian):**
```
Input No RM
   │
   ▼
Cari pasien di Linked List ──[Tidak ditemukan]──► [ERROR]
   │ [Ditemukan]
   ▼
Enqueue ke Queue ──[Penuh]──► [ERROR] Antrian penuh
   │ [Sukses]
   ▼
Set status = "Menunggu"
   │
   ▼
[SUKSES] Pasien masuk antrian
```

**Dequeue (Layani Pasien):**
```
Dequeue dari Queue ──[Kosong]──► [ERROR] Antrian kosong
   │ [Sukses]
   ▼
Set status = "Selesai"
   │
   ▼
Push ke Stack Riwayat
   │
   ▼
Update status di Linked List & Array
   │
   ▼
[SUKSES] Pasien telah dilayani, riwayat dicatat
```

#### Flow Riwayat Medis (Menu 8)

```
Tampilkan Riwayat  →  Stack.tampilkan() (dari top ke bottom)
Pop Riwayat        →  Stack.pop() → tampilkan data terbaru
```

#### Diagram Alur Data Antar Struktur

```
                    ┌─────────────┐
   Tambah Pasien ──►│ Linked List │◄── Cari/Update/Hapus
                    └──────┬──────┘
                           │ sinkron
                    ┌──────▼──────┐
                    │    Array    │── Sorting / Binary Search
                    └─────────────┘

   Enqueue ──► ┌───────┐    Dequeue ──► ┌───────┐
               │ Queue │ ─────────────► │ Stack │
               └───────┘   push riwayat └───────┘

   Validasi Poli ──► ┌──────┐
                     │ Tree │
                     └──────┘

   Rujukan Unit ───► ┌───────┐
                     │ Graph │── BFS (jalur terpendek)
                     └───────┘── DFS (cek jalur)
```

---

### 7.6 Error Handling

Sistem menerapkan validasi dan penanganan error pada setiap operasi penting. Pesan error ditampilkan dengan format `[ERROR]`, sukses dengan `[SUKSES]`, dan informasi dengan `[INFO]`.

#### Tabel Error Handling

| Operasi | Kondisi Error | Pesan | Aksi Sistem |
|---------|---------------|-------|-------------|
| Tambah pasien | Field kosong (`noRM`, `nama`, `poli`) | `[ERROR] Data tidak boleh kosong!` | Batalkan operasi |
| Tambah pasien | No RM duplikat | `[ERROR] Duplikasi data! No RM '...' sudah terdaftar.` | Batalkan operasi |
| Tambah pasien | Poli tidak valid | `[ERROR] Poli '...' tidak ditemukan.` | Batalkan operasi |
| Tambah pasien | Array penuh (≥ 150) | `[ERROR] Array penuh! Kapasitas maksimal 150 pasien.` | Rollback linked list |
| Cari pasien | No RM kosong | `[ERROR] No RM tidak boleh kosong!` | Batalkan operasi |
| Cari pasien | Data tidak ditemukan | `[ERROR] Data pasien dengan No RM '...' tidak ditemukan.` | Batalkan operasi |
| Update pasien | Data tidak ditemukan | `[ERROR] Data pasien tidak ditemukan.` | Batalkan operasi |
| Hapus pasien | Data tidak ditemukan | `[ERROR] Data pasien tidak ditemukan.` | Batalkan operasi |
| Enqueue antrian | Pasien tidak ditemukan | `[ERROR] Pasien tidak ditemukan.` | Batalkan operasi |
| Enqueue antrian | Antrian penuh | `[ERROR] Antrian penuh!` | Batalkan operasi |
| Dequeue antrian | Antrian kosong | `[ERROR] Antrian kosong! Tidak ada pasien yang dilayani.` | Batalkan operasi |
| Pop riwayat | Stack kosong | `[ERROR] Stack kosong! Tidak ada riwayat.` | Batalkan operasi |
| Menu/submenu | Pilihan tidak valid | `[ERROR] Menu/Pilihan tidak valid.` | Kembali ke menu |

#### Strategi Error Handling

1. **Validasi input di lapisan UI (`main.cpp`)** — Mengecek data kosong sebelum memanggil operasi struktur data.
2. **Return value boolean** — Fungsi `tambah`, `hapus`, `enqueue`, `dequeue`, `push`, `pop` mengembalikan `true`/`false` untuk indikasi sukses/gagal.
3. **Rollback transaksi** — Saat penambahan ke array gagal setelah linked list berhasil, data di linked list dihapus kembali (konsistensi data).
4. **Pesan informatif** — Setiap error disertai konteks (No RM, nama poli, dll.) agar pengguna mudah memperbaiki input.
5. **Pembersihan buffer input** — Fungsi `bersihkanBuffer()` mencegah sisa karakter newline mengganggu input `getline()` berikutnya.

#### Contoh Implementasi Error Handling

```cpp
// Validasi data kosong
if (p.noRM.empty() || p.nama.empty() || p.poli.empty()) {
    cout << "[ERROR] Data tidak boleh kosong!\n";
    return;
}

// Validasi duplikasi
if (linkedList.duplikat(p.noRM) || arrayPasien.duplikat(p.noRM)) {
    cout << "[ERROR] Duplikasi data! No RM '" << p.noRM << "' sudah terdaftar.\n";
    return;
}

// Rollback jika array penuh
linkedList.tambah(p);
if (!arrayPasien.tambah(p)) {
    cout << "[ERROR] Array penuh! Kapasitas maksimal " << MAX_PASIEN << " pasien.\n";
    linkedList.hapus(p.noRM);  // rollback
    return;
}
```

---

## Lampiran: Menu Sistem

```
========================================
  SISTEM MANAJEMEN ANTRIAN & REKAM MEDIS
         KLINIK E-HEALTH (C++)
========================================
  1. Tambah Data Pasien
  2. Cari Data Pasien
  3. Update Data Pasien
  4. Hapus Data Pasien
  5. Tampilkan Semua Pasien (Linked List)
  6. Tampilkan Data Pasien (Array)
  7. Kelola Antrian Pasien (Queue)
  8. Riwayat Medis (Stack)
  9. Struktur Poli Klinik (Tree)
 10. Statistik Pasien
 11. Graph Rujukan Poli (BFS/DFS)
 12. Sorting Data Pasien
 13. Searching & Analisis Big O
  0. Keluar
========================================
```

### Submenu Graph (Menu 11)
1. Tampilkan Jaringan Rujukan  
2. Telusuri BFS  
3. Telusuri DFS  
4. Cari Jalur Rujukan Terpendek (BFS)  
5. Cek Ada Jalur Rujukan (DFS)

### Submenu Sorting (Menu 12)
1. Bubble Sort  
2. Selection Sort  
3. Insertion Sort  
4. Tampilkan Data Array  

### Submenu Searching & Big O (Menu 13)
1. Bandingkan Linear vs Binary Search  
2. Tampilkan Analisis Big O Sistem  
3. Sort No RM dulu lalu Binary Search  

---

*Dokumentasi ini disusun berdasarkan implementasi source code project `uts-strukturdata`.*

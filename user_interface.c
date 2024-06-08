#include <gtk/gtk.h>
#include <glib/gi18n.h>
#include <string.h>
// #include 

// typedef struct{
//     char *str1;
// }string;

// static void on_button_clicked(GtkWidget *widget, gpointer data) {
//     string *str = data;
//     g_print("%s\n", str->str1);
// }

static void activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *window, *sidebar, *stack, *box, *header, *button, *label, *entry;
    GtkWidget *grid1, *grid2, *grid3, *grid4, *grid5, *grid6, *grid7, *grid8, *grid9, *grid10, *grid11, *grid12, *grid13;
    GtkStackPage *page1, *page2, *page3, *page4, *page5, *page6, *page7, *page8, *page9, *page10, *page11, *page12, *page13;
    // const char * pages[] = {
    //     "Selamat datang!",                      //page1
    //     "Tambah data pasien",                   //page2
    //     "Ubah data pasien",                     //page3
    //     "Hapus data pasien",                    //page4
    //     "Cari data pasien",                     //page5
    //     "Tambah riwayat medis pasien",          //page6
    //     "Ubah riwayat medis pasien",            //page7
    //     "Hapus riwayat medis pasien",           //page8
    //     "Cari riwayat medis pasien",            //page9
    //     "Kirim data dan riwayat medis pasien",  //page10
    //     "Akses laporan keuangan",               //page11
    //     "Statistik riwayat medis",              //page12
    //     "Informasi jadwal kontrol pasien",      //page13
    //     NULL
    // };
    // const char *c = NULL;
    // guint i;
    
    window = gtk_application_window_new(app);
    gtk_window_set_resizable(GTK_WINDOW(window), TRUE);

    header = gtk_header_bar_new();
    gtk_window_set_titlebar (GTK_WINDOW(window), header);
    gtk_window_set_title(GTK_WINDOW(window), "Klinik X Healthcare System");
    g_object_add_weak_pointer (G_OBJECT (window), (gpointer *)&window);
    gtk_window_set_default_size(GTK_WINDOW(window), 1000, 600);

    box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    sidebar = gtk_stack_sidebar_new();
    gtk_box_append(GTK_BOX(box), sidebar);

    stack = gtk_stack_new();
    gtk_stack_set_transition_type(GTK_STACK(stack), GTK_STACK_TRANSITION_TYPE_SLIDE_UP_DOWN);
    gtk_stack_sidebar_set_stack(GTK_STACK_SIDEBAR(sidebar), GTK_STACK(stack));
    gtk_widget_set_hexpand(GTK_WIDGET(stack), TRUE);
    gtk_box_append(GTK_BOX(box), stack);

    gtk_window_set_child(GTK_WINDOW(window), box);
    
    //Page 1 (Selamat datang)
    {grid1 = gtk_grid_new();
    page1 = gtk_stack_add_child(GTK_STACK(stack), grid1);
    gtk_stack_page_set_title(GTK_STACK_PAGE(page1), "Selamat datang!");
    label = gtk_label_new("Selamat datang di Klinik X Healthcare System!\nSilakan pilih aksi yang ingin dilakukan di sidebar sebelah kiri.");
    gtk_grid_attach(GTK_GRID(grid1), label, 0, 0, 1, 1);
    gtk_widget_set_hexpand(GTK_WIDGET(label), TRUE);
    gtk_widget_set_vexpand(GTK_WIDGET(label), TRUE);
    }
    
    //Page 2 (Tambah data pasien)
    {grid2 = gtk_grid_new();
    page2 = gtk_stack_add_child(GTK_STACK(stack), grid2);
    gtk_stack_page_set_title(GTK_STACK_PAGE(page2), "Tambah data pasien");
    
    label = gtk_label_new("Masukkan data pasien baru.");
    gtk_grid_attach(GTK_GRID(grid2), label, 0, 0, 2, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_START);

    label = gtk_label_new("Nama lengkap\t: ");
    gtk_grid_attach(GTK_GRID(grid2), label, 0, 1, 1, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_START);

    entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid2), entry, 1, 1, 2, 1);
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry), "Contoh: Anton");

    // string *strCallBack = g_new0(string, 1);
    // strCallBack->str1 = gtk_entry_get_text(GTK_ENTRY(entry));

    label = gtk_label_new("Alamat\t\t\t: ");
    gtk_grid_attach(GTK_GRID(grid2), label, 0, 2, 1, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_START);

    entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid2), entry, 1, 2, 2, 1);
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry), "Contoh: Jakarta");

    label = gtk_label_new("Tempat lahir\t\t: ");
    gtk_grid_attach(GTK_GRID(grid2), label, 0, 3, 1, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_START);

    entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid2), entry, 1, 3, 2, 1);
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry), "Contoh: Bandung");

    label = gtk_label_new("Tanggal lahir\t\t: ");
    gtk_grid_attach(GTK_GRID(grid2), label, 0, 4, 1, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_START);

    entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid2), entry, 1, 4, 2, 1);
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry), "Format: tanggal-bulan-tahun");

    label = gtk_label_new("No BPJS\t\t\t: ");
    gtk_grid_attach(GTK_GRID(grid2), label, 0, 5, 1, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_START);

    entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid2), entry, 1, 5, 2, 1);
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry), "Contoh: 1234567890");

    label = gtk_label_new("ID pasien\t\t: ");
    gtk_grid_attach(GTK_GRID(grid2), label, 0, 6, 1, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_START);

    entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid2), entry, 1, 6, 2, 1);
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry), "Contoh: KX 1234567");

    button = gtk_button_new_with_label("Tambahkan");
    gtk_grid_attach(GTK_GRID(grid2), button, 1, 7, 1, 1);
    gtk_widget_set_halign(button, GTK_ALIGN_END);

    //g_signal_connect_swapped (G_OBJECT(button), "clicked", G_CALLBACK (on_button_clicked), strCallBack);

    }

    //Page 3 (Ubah data pasien)
    {grid3 = gtk_grid_new();
    page3 = gtk_stack_add_child(GTK_STACK(stack), grid3);
    gtk_stack_page_set_title(GTK_STACK_PAGE(page3), "Ubah data pasien");

    label = gtk_label_new("Masukkan data pasien yang ingin diubah.");
    gtk_grid_attach(GTK_GRID(grid3), label, 0, 0, 3, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_START);

    label = gtk_label_new("Nama lengkap\t: ");
    gtk_grid_attach(GTK_GRID(grid3), label, 0, 1, 1, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_START);

    entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid3), entry, 1, 1, 2, 1);
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry), "Contoh: Anton");

    label = gtk_label_new("Alamat\t\t\t: ");
    gtk_grid_attach(GTK_GRID(grid3), label, 0, 2, 1, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_START);

    entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid3), entry, 1, 2, 2, 1);
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry), "Contoh: Jakarta");

    label = gtk_label_new("Tempat lahir\t\t: ");
    gtk_grid_attach(GTK_GRID(grid3), label, 0, 3, 1, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_START);

    entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid3), entry, 1, 3, 2, 1);
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry), "Contoh: Bandung");

    label = gtk_label_new("Tanggal lahir\t\t: ");
    gtk_grid_attach(GTK_GRID(grid3), label, 0, 4, 1, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_START);

    entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid3), entry, 1, 4, 2, 1);
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry), "Format: tanggal-bulan-tahun");

    label = gtk_label_new("No BPJS\t\t\t: ");
    gtk_grid_attach(GTK_GRID(grid3), label, 0, 5, 1, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_START);

    entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid3), entry, 1, 5, 2, 1);
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry), "Contoh: 1234567890");

    label = gtk_label_new("ID pasien\t\t: ");
    gtk_grid_attach(GTK_GRID(grid3), label, 0, 6, 1, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_START);

    entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid3), entry, 1, 6, 2, 1);
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry), "Contoh: KX 1234567");

    button = gtk_button_new_with_label("Ubah");
    gtk_grid_attach(GTK_GRID(grid3), button, 1, 7, 1, 1);
    gtk_widget_set_halign(button, GTK_ALIGN_END);
    }

    //Page 4 (Hapus data pasien)
    {grid4 = gtk_grid_new();
    page4 = gtk_stack_add_child(GTK_STACK(stack), grid4);
    gtk_stack_page_set_title(GTK_STACK_PAGE(page4), "Hapus data pasien");

    label = gtk_label_new("Masukkan ID pasien yang ingin dihapus.");
    gtk_grid_attach(GTK_GRID(grid4), label, 0, 0, 2, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_START);

    label = gtk_label_new("ID pasien\t\t: ");
    gtk_grid_attach(GTK_GRID(grid4), label, 0, 1, 1, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_START);

    entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid4), entry, 1, 1, 2, 1);
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry), "Contoh: KX 1234567");

    button = gtk_button_new_with_label("Hapus");
    gtk_grid_attach(GTK_GRID(grid4), button, 1, 7, 1, 1);
    gtk_widget_set_halign(button, GTK_ALIGN_END);
    }

    //Page 5 (Cari data pasien)
    {grid5 = gtk_grid_new();
    page5 = gtk_stack_add_child(GTK_STACK(stack), grid5);
    gtk_stack_page_set_title(GTK_STACK_PAGE(page5), "Cari data pasien");

    label = gtk_label_new("Masukkan ID pasien yang ingin dicari.");
    gtk_grid_attach(GTK_GRID(grid5), label, 0, 0, 3, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_START);

    label = gtk_label_new("ID pasien\t\t: ");
    gtk_grid_attach(GTK_GRID(grid5), label, 0, 1, 1, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_START);

    entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid5), entry, 1, 1, 2, 1);
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry), "Contoh: KX 1234567");

    button = gtk_button_new_with_label("Cari");
    gtk_grid_attach(GTK_GRID(grid5), button, 1, 7, 1, 1);
    gtk_widget_set_halign(button, GTK_ALIGN_END);
    }

    //Page 6 (Tambah riwayat medis pasien)
    {grid6 = gtk_grid_new();
    page6 = gtk_stack_add_child(GTK_STACK(stack), grid6);
    gtk_stack_page_set_title(GTK_STACK_PAGE(page6), "Tambah riwayat medis pasien");

    label = gtk_label_new("Masukkan ID pasien yang ingin ditambahkan riwayat medis.");
    gtk_grid_attach(GTK_GRID(grid6), label, 0, 0, 3, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_START);

    label = gtk_label_new("ID pasien\t\t: ");
    gtk_grid_attach(GTK_GRID(grid6), label, 0, 1, 1, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_START);

    entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid6), entry, 1, 1, 2, 1);
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry), "Contoh: KX 1234567");

    label = gtk_label_new("Tanggal kunjungan\t: ");
    gtk_grid_attach(GTK_GRID(grid6), label, 0, 2, 1, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_START);

    entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid6), entry, 1, 2, 2, 1);
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry), "Format: tanggal-bulan-tahun");

    label = gtk_label_new("Diagnosis\t\t: ");
    gtk_grid_attach(GTK_GRID(grid6), label, 0, 3, 1, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_START);

    entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid6), entry, 1, 3, 2, 1);
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry), "Contoh: Dehidrasi");

    label = gtk_label_new("Tindakan\t\t\t: ");
    gtk_grid_attach(GTK_GRID(grid6), label, 0, 4, 1, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_START);

    entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid6), entry, 1, 4, 2, 1);
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry), "Contoh: Vaksinasi");

    label = gtk_label_new("Jadwal kontrol\t: ");
    gtk_grid_attach(GTK_GRID(grid6), label, 0, 5, 1, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_START);

    entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid6), entry, 1, 5, 2, 1);
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry), "Format: tanggal-bulan-tahun");

    button = gtk_button_new_with_label("Tambahkan");
    gtk_grid_attach(GTK_GRID(grid6), button, 1, 6, 1, 1);
    gtk_widget_set_halign(button, GTK_ALIGN_END);
    }
    
    //Page 7 (Ubah riwayat medis pasien)
    {grid7 = gtk_grid_new();
    page7 = gtk_stack_add_child(GTK_STACK(stack), grid7);
    gtk_stack_page_set_title(GTK_STACK_PAGE(page7), "Ubah riwayat medis pasien");

    label = gtk_label_new("Masukkan ID pasien yang ingin diubah riwayat medis.");
    gtk_grid_attach(GTK_GRID(grid7), label, 0, 0, 3, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_START);

    label = gtk_label_new("ID pasien\t\t: ");
    gtk_grid_attach(GTK_GRID(grid7), label, 0, 1, 1, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_START);

    entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid7), entry, 1, 1, 2, 1);
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry), "Contoh: KX 1234567");

    label = gtk_label_new("Tanggal kunjungan\t: ");
    gtk_grid_attach(GTK_GRID(grid7), label, 0, 2, 1, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_START);

    entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid7), entry, 1, 2, 2, 1);
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry), "Format: tanggal-bulan-tahun");

    label = gtk_label_new("Diagnosis\t\t: ");
    gtk_grid_attach(GTK_GRID(grid7), label, 0, 3, 1, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_START);

    entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid7), entry, 1, 3, 2, 1);
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry), "Contoh: Dehidrasi");

    label = gtk_label_new("Tindakan\t\t\t: ");
    gtk_grid_attach(GTK_GRID(grid7), label, 0, 4, 1, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_START);

    entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid7), entry, 1, 4, 2, 1);
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry), "Contoh: Vaksinasi");

    label = gtk_label_new("Jadwal kontrol\t: ");
    gtk_grid_attach(GTK_GRID(grid7), label, 0, 5, 1, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_START);

    entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid7), entry, 1, 5, 2, 1);
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry), "Contoh: tanggal-bulan-tahun");

    button = gtk_button_new_with_label("Tambahkan");
    gtk_grid_attach(GTK_GRID(grid7), button, 1, 6, 1, 1);
    gtk_widget_set_halign(button, GTK_ALIGN_END);
    }

    //Page 8 (Hapus riwayat medis pasien)
    {grid8 = gtk_grid_new();
    page8 = gtk_stack_add_child(GTK_STACK(stack), grid8);
    gtk_stack_page_set_title(GTK_STACK_PAGE(page8), "Hapus riwayat medis pasien");

    label = gtk_label_new("Masukkan ID pasien yang ingin dihapus riwayat medis.");
    gtk_grid_attach(GTK_GRID(grid8), label, 0, 0, 3, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_START);

    label = gtk_label_new("ID pasien\t\t: ");
    gtk_grid_attach(GTK_GRID(grid8), label, 0, 1, 1, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_START);

    entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid8), entry, 1, 1, 2, 1);
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry), "Contoh: KX 1234567");

    button = gtk_button_new_with_label("Hapus");
    gtk_grid_attach(GTK_GRID(grid8), button, 1, 7, 1, 1);
    gtk_widget_set_halign(button, GTK_ALIGN_END);
    }

    //Page 9 (Cari riwayat medis pasien)
    {grid9 = gtk_grid_new();
    page9 = gtk_stack_add_child(GTK_STACK(stack), grid9);
    gtk_stack_page_set_title(GTK_STACK_PAGE(page9), "Cari riwayat medis pasien");

    label = gtk_label_new("Masukkan ID pasien yang ingin dicari riwayat medis.");
    gtk_grid_attach(GTK_GRID(grid9), label, 0, 0, 3, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_START);

    label = gtk_label_new("ID pasien\t\t: ");
    gtk_grid_attach(GTK_GRID(grid9), label, 0, 1, 1, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_START);

    entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid9), entry, 1, 1, 2, 1);
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry), "Contoh: KX 1234567");

    button = gtk_button_new_with_label("Cari");
    gtk_grid_attach(GTK_GRID(grid9), button, 1, 2, 1, 1);
    gtk_widget_set_halign(button, GTK_ALIGN_END);

    label = gtk_label_new("Riwayat medis\t: ");
    gtk_grid_attach(GTK_GRID(grid9), label, 0, 3, 1, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_START);
    }

    //Page 10 (Kirim data dan riwayat medis pasien ke petugas medis)
    {grid10 = gtk_grid_new();
    page10 = gtk_stack_add_child(GTK_STACK(stack), grid10);
    gtk_stack_page_set_title(GTK_STACK_PAGE(page10), "Kirim data dan riwayat medis pasien ke petugas medis");

    label = gtk_label_new("Masukkan ID pasien yang ingin dikirim ke petugas medis.");
    gtk_grid_attach(GTK_GRID(grid10), label, 0, 0, 4, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_START);

    label = gtk_label_new("ID pasien\t\t: ");
    gtk_grid_attach(GTK_GRID(grid10), label, 0, 1, 1, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_START);

    entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid10), entry, 1, 1, 2, 1);
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry), "Contoh: KX 1234567");

    button = gtk_button_new_with_label("Kirim");
    gtk_grid_attach(GTK_GRID(grid10), button, 1, 2, 1, 1);
    gtk_widget_set_halign(button, GTK_ALIGN_END);

    label = gtk_label_new("Riwayat medis\t: ");
    gtk_grid_attach(GTK_GRID(grid10), label, 0, 3, 1, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_START);
    }

    //Page 11 (Akses laporan keuangan)
    {grid11 = gtk_grid_new();
    page11 = gtk_stack_add_child(GTK_STACK(stack), grid11);
    gtk_stack_page_set_title(GTK_STACK_PAGE(page11), "Akses laporan keuangan");

    label = gtk_label_new("Laporan keuangan Klinik X");
    gtk_grid_attach(GTK_GRID(grid11), label, 0, 0, 1, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_START);

    label = gtk_label_new("Data laporan keuangan");
    gtk_grid_attach(GTK_GRID(grid11), label, 0, 1, 1, 1);
    gtk_widget_set_hexpand(GTK_WIDGET(label), TRUE);
    gtk_widget_set_vexpand(GTK_WIDGET(label), TRUE);
    }

    //Page 12 (Statistik riwayat medis)
    {grid12 = gtk_grid_new();
    page12 = gtk_stack_add_child(GTK_STACK(stack), grid12);
    gtk_stack_page_set_title(GTK_STACK_PAGE(page12), "Statistik riwayat medis");

    label = gtk_label_new("Statistik riwayat medis");
    gtk_grid_attach(GTK_GRID(grid12), label, 0, 0, 1, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_START);

    label = gtk_label_new("Data riwayat medis");
    gtk_grid_attach(GTK_GRID(grid12), label, 0, 1, 1, 1);
    gtk_widget_set_hexpand(GTK_WIDGET(label), TRUE);
    gtk_widget_set_vexpand(GTK_WIDGET(label), TRUE);
    }

    //Page 13 (Informasi jadwal kontrol pasien)
    {grid13 = gtk_grid_new();
    page13 = gtk_stack_add_child(GTK_STACK(stack), grid13);
    gtk_stack_page_set_title(GTK_STACK_PAGE(page13), "Informasi jadwal kontrol pasien");

    label = gtk_label_new("Masukkan bulan jadwal kontrol pasien");
    gtk_grid_attach(GTK_GRID(grid13), label, 0, 0, 3, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_START);

    label = gtk_label_new("Bulan\t\t: ");
    gtk_grid_attach(GTK_GRID(grid13), label, 0, 1, 1, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_START);

    entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid13), entry, 1, 1, 2, 1);
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry), "Contoh: Januari");

    button = gtk_button_new_with_label("Cari");
    gtk_grid_attach(GTK_GRID(grid13), button, 1, 2, 1, 1);
    gtk_widget_set_halign(button, GTK_ALIGN_END);

    label = gtk_label_new("Jadwal kontrol\t: ");
    gtk_grid_attach(GTK_GRID(grid13), label, 0, 3, 1, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_START);
    }

    gtk_window_present (GTK_WINDOW (window));
}

int main(int argc, char *argv[]) {
    GtkApplication *app;
    GtkWidget *window, *sidebar, *stack, *box, *widget, *header;
    int status;

    app = gtk_application_new ("test.stackSideBar", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
    status = g_application_run (G_APPLICATION (app), argc, argv);
    g_object_unref (app);
    return status;
}
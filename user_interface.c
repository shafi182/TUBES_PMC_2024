#include <gtk/gtk.h>
#include <glib/gi18n.h>
#include <glib/gstdio.h>
#include <string.h>

#include "variable.h"
// #include "variable.c"
#include "reader.c"
#include "writer.c"
#include "DataRiwayat.c"

// typedef struct{
//     dataPasien *dataPasienHead;
//     riwayatDiagnosis *riwayatDiagnosisHead;
//     const char *str1;
//     const char *str2;
//     const char *str3;
//     const char *str4;
//     const char *str5;
//     const char *str6;
//     const char *str7;
//     const char *strOutput;
//     GtkWidget *labelOutput;
// }strCallbackData;

static void on_button_clicked(GtkWidget *widget, gpointer data) {
    strCallbackData *str = data;
    g_print("Data inside struct: \n");
    g_print("%s\n", str->str1);
    g_print("%s\n", str->str2);
    g_print("%s\n", str->str3);
    g_print("%s\n", str->str4);
    g_print("%s\n", str->str5);
    g_print("%s\n", str->str6);
    g_print("%s\n", str->str7);
    g_print("%s\n", str->strOutput);
}

static void *get_entry_text1(GtkEntry *entry, gpointer user_data) {   
    strCallbackData *str = user_data;
    const gchar *text = gtk_entry_buffer_get_text(GTK_ENTRY_BUFFER(gtk_entry_get_buffer(entry)));
    str->str1 = text;
}

static void *get_entry_text2(GtkEntry *entry, gpointer user_data) {   
    strCallbackData *str = user_data;
    const gchar *text = gtk_entry_buffer_get_text(GTK_ENTRY_BUFFER(gtk_entry_get_buffer(entry)));
    str->str2 = text;
}

static void *get_entry_text3(GtkEntry *entry, gpointer user_data) {   
    strCallbackData *str = user_data;
    const gchar *text = gtk_entry_buffer_get_text(GTK_ENTRY_BUFFER(gtk_entry_get_buffer(entry)));
    str->str3 = text;
}

static void *get_entry_text4(GtkEntry *entry, gpointer user_data) {   
    strCallbackData *str = user_data;
    const gchar *text = gtk_entry_buffer_get_text(GTK_ENTRY_BUFFER(gtk_entry_get_buffer(entry)));
    str->str4 = text;
}

static void *get_entry_text5(GtkEntry *entry, gpointer user_data) {   
    strCallbackData *str = user_data;
    const gchar *text = gtk_entry_buffer_get_text(GTK_ENTRY_BUFFER(gtk_entry_get_buffer(entry)));
    str->str5 = text;
}

static void *get_entry_text6(GtkEntry *entry, gpointer user_data) {   
    strCallbackData *str = user_data;
    const gchar *text = gtk_entry_buffer_get_text(GTK_ENTRY_BUFFER(gtk_entry_get_buffer(entry)));
    str->str6 = text;
}

static void *get_entry_text7(GtkEntry *entry, gpointer user_data) {   
    strCallbackData *str = user_data;
    const gchar *text = gtk_entry_buffer_get_text(GTK_ENTRY_BUFFER(gtk_entry_get_buffer(entry)));
    str->str7 = text;
}

static void *set_label_text(GtkButton *button, gpointer user_data) {
    strCallbackData *str = user_data;
    //str->strOutput = str->str1;//"Output testing";
    gtk_label_set_text(GTK_LABEL(str->labelOutput), str->strOutput);
}

static void activate(GtkApplication *app, gpointer user_data) {
    // Inisialisasi
    GtkWidget *window, *sidebar, *stack, *box, *header, *button, *label, *entry;
    GtkWidget *grid1, *grid2, *grid3, *grid4, *grid5, *grid6, *grid7, *grid8, *grid9, *grid10, *grid11, *grid12, *grid13;
    GtkStackPage *page1, *page2, *page3, *page4, *page5, *page6, *page7, *page8, *page9, *page10, *page11, *page12, *page13;

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

    gtk_window_present (GTK_WINDOW (window));
    
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
    {
    strCallbackData *strCallBack2 = g_new0(strCallbackData, 1);
    strCallBack2->dataPasienHead = dataPasienHead;

    grid2 = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(grid2), 10);
    gtk_grid_set_column_spacing(GTK_GRID(grid2), 10);
    page2 = gtk_stack_add_child(GTK_STACK(stack), grid2);
    gtk_stack_page_set_title(GTK_STACK_PAGE(page2), "Tambah data pasien");
    
    label = gtk_label_new("Masukkan data pasien baru.");
    gtk_grid_attach(GTK_GRID(grid2), label, 0, 0, 2, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_START);
    gtk_widget_set_margin_start(label, 10);

    label = gtk_label_new("Nama lengkap\t: ");
    gtk_grid_attach(GTK_GRID(grid2), label, 0, 1, 1, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_START);
    gtk_widget_set_margin_start(label, 10);

    entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid2), entry, 1, 1, 2, 1);
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry), "Anton");
    gtk_widget_set_hexpand(GTK_WIDGET(entry), TRUE);
    gtk_widget_set_margin_end(GTK_WIDGET(entry), 10);
    g_signal_connect (G_OBJECT(entry), "changed", G_CALLBACK (get_entry_text1), strCallBack2);

    label = gtk_label_new("Alamat\t\t\t: ");
    gtk_grid_attach(GTK_GRID(grid2), label, 0, 2, 1, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_START);
    gtk_widget_set_margin_start(label, 10);
    
    entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid2), entry, 1, 2, 2, 1);
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry), "Jakarta");
    gtk_widget_set_hexpand(GTK_WIDGET(entry), TRUE);
    gtk_widget_set_margin_end(GTK_WIDGET(entry), 10);
    g_signal_connect (G_OBJECT(entry), "changed", G_CALLBACK (get_entry_text2), strCallBack2);

    label = gtk_label_new("Kota\t\t\t: ");
    gtk_grid_attach(GTK_GRID(grid2), label, 0, 3, 1, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_START);
    gtk_widget_set_margin_start(label, 10);
    
    entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid2), entry, 1, 3, 2, 1);
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry), "Bali");
    gtk_widget_set_hexpand(GTK_WIDGET(entry), TRUE);
    gtk_widget_set_margin_end(GTK_WIDGET(entry), 10);
    g_signal_connect (G_OBJECT(entry), "changed", G_CALLBACK (get_entry_text3), strCallBack2);

    label = gtk_label_new("Tempat lahir\t\t: ");
    gtk_grid_attach(GTK_GRID(grid2), label, 0, 4, 1, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_START);
    gtk_widget_set_margin_start(label, 10);

    entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid2), entry, 1, 4, 2, 1);
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry), "Bandung");
    gtk_widget_set_hexpand(GTK_WIDGET(entry), TRUE);
    gtk_widget_set_margin_end(GTK_WIDGET(entry), 10);
    g_signal_connect (G_OBJECT(entry), "changed", G_CALLBACK (get_entry_text4), strCallBack2);

    label = gtk_label_new("Tanggal lahir\t\t: ");
    gtk_grid_attach(GTK_GRID(grid2), label, 0, 5, 1, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_START);
    gtk_widget_set_margin_start(label, 10);

    entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid2), entry, 1, 5, 2, 1);
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry), "Tanggal-bulan-tahun");
    gtk_widget_set_hexpand(GTK_WIDGET(entry), TRUE);
    gtk_widget_set_margin_end(GTK_WIDGET(entry), 10);
    g_signal_connect (G_OBJECT(entry), "changed", G_CALLBACK (get_entry_text5), strCallBack2);

    label = gtk_label_new("No BPJS\t\t\t: ");
    gtk_grid_attach(GTK_GRID(grid2), label, 0, 6, 1, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_START);
    gtk_widget_set_margin_start(label, 10);

    entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid2), entry, 1, 6, 2, 1);
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry), "1234567890");
    gtk_widget_set_hexpand(GTK_WIDGET(entry), TRUE);
    gtk_widget_set_margin_end(GTK_WIDGET(entry), 10);
    g_signal_connect (G_OBJECT(entry), "changed", G_CALLBACK (get_entry_text6), strCallBack2);

    label = gtk_label_new("ID pasien\t\t: ");
    gtk_grid_attach(GTK_GRID(grid2), label, 0, 7, 1, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_START);
    gtk_widget_set_margin_start(label, 10);

    entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid2), entry, 1, 7, 2, 1);
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry), "KX 1234567");
    gtk_widget_set_hexpand(GTK_WIDGET(entry), TRUE);
    gtk_widget_set_margin_end(GTK_WIDGET(entry), 10);
    g_signal_connect (G_OBJECT(entry), "changed", G_CALLBACK (get_entry_text7), strCallBack2);

    button = gtk_button_new_with_label("Tambahkan");
    gtk_grid_attach(GTK_GRID(grid2), button, 1, 8, 1, 1);
    gtk_widget_set_halign(button, GTK_ALIGN_CENTER);
    g_signal_connect (G_OBJECT(button), "clicked", G_CALLBACK (on_button_clicked), strCallBack2);

    strCallBack2->labelOutput = gtk_label_new("Lengkapi data pasien terlebih dahulu");
    gtk_grid_attach(GTK_GRID(grid2), strCallBack2->labelOutput, 1, 9, 1, 1);
    gtk_widget_set_halign(strCallBack2->labelOutput, GTK_ALIGN_CENTER);
    gtk_widget_set_margin_start(strCallBack2->labelOutput, 10);
    
    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(tambahData), strCallBack2);
    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(set_label_text), strCallBack2);
    }

    //Page 3 (Ubah data pasien)
    {
    strCallbackData *strCallBack3 = g_new0(strCallbackData, 1);
    
    grid3 = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(grid3), 10);
    gtk_grid_set_column_spacing(GTK_GRID(grid3), 10);
    page3 = gtk_stack_add_child(GTK_STACK(stack), grid3);
    gtk_stack_page_set_title(GTK_STACK_PAGE(page3), "Ubah data pasien");

    label = gtk_label_new("Masukkan data pasien yang ingin diubah.");
    gtk_grid_attach(GTK_GRID(grid3), label, 0, 0, 3, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_START);
    gtk_widget_set_margin_start(label, 10);

    label = gtk_label_new("Nama lengkap\t: ");
    gtk_grid_attach(GTK_GRID(grid3), label, 0, 1, 1, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_START);
    gtk_widget_set_margin_start(label, 10);

    entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid3), entry, 1, 1, 2, 1);
    gtk_widget_set_hexpand(GTK_WIDGET(entry), TRUE);
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry), "Anton");
    gtk_widget_set_hexpand(GTK_WIDGET(entry), TRUE);
    gtk_widget_set_margin_end(GTK_WIDGET(entry), 10);
    g_signal_connect (G_OBJECT(entry), "changed", G_CALLBACK (get_entry_text1), strCallBack3);

    label = gtk_label_new("Alamat\t\t\t: ");
    gtk_grid_attach(GTK_GRID(grid3), label, 0, 2, 1, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_START);
    gtk_widget_set_margin_start(label, 10);

    entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid3), entry, 1, 2, 2, 1);
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry), "Jakarta");
    gtk_widget_set_hexpand(GTK_WIDGET(entry), TRUE);
    gtk_widget_set_margin_end(GTK_WIDGET(entry), 10);
    g_signal_connect (G_OBJECT(entry), "changed", G_CALLBACK (get_entry_text2), strCallBack3);

    label = gtk_label_new("Tempat lahir\t\t: ");
    gtk_grid_attach(GTK_GRID(grid3), label, 0, 3, 1, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_START);
    gtk_widget_set_margin_start(label, 10);

    entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid3), entry, 1, 3, 2, 1);
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry), "Bandung");
    gtk_widget_set_hexpand(GTK_WIDGET(entry), TRUE);
    gtk_widget_set_margin_end(GTK_WIDGET(entry), 10);
    g_signal_connect (G_OBJECT(entry), "changed", G_CALLBACK (get_entry_text3), strCallBack3);

    label = gtk_label_new("Tanggal lahir\t\t: ");
    gtk_grid_attach(GTK_GRID(grid3), label, 0, 4, 1, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_START);
    gtk_widget_set_margin_start(label, 10);

    entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid3), entry, 1, 4, 2, 1);
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry), "Tanggal-bulan-tahun");
    gtk_widget_set_hexpand(GTK_WIDGET(entry), TRUE);
    gtk_widget_set_margin_end(GTK_WIDGET(entry), 10);
    g_signal_connect (G_OBJECT(entry), "changed", G_CALLBACK (get_entry_text4), strCallBack3);

    label = gtk_label_new("No BPJS\t\t\t: ");
    gtk_grid_attach(GTK_GRID(grid3), label, 0, 5, 1, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_START);
    gtk_widget_set_margin_start(label, 10);

    entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid3), entry, 1, 5, 2, 1);
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry), "1234567890");
    gtk_widget_set_hexpand(GTK_WIDGET(entry), TRUE);
    gtk_widget_set_margin_end(GTK_WIDGET(entry), 10);
    g_signal_connect (G_OBJECT(entry), "changed", G_CALLBACK (get_entry_text5), strCallBack3);

    label = gtk_label_new("ID pasien\t\t: ");
    gtk_grid_attach(GTK_GRID(grid3), label, 0, 6, 1, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_START);
    gtk_widget_set_margin_start(label, 10);

    entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid3), entry, 1, 6, 2, 1);
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry), "KX 1234567");
    gtk_widget_set_hexpand(GTK_WIDGET(entry), TRUE);
    gtk_widget_set_margin_end(GTK_WIDGET(entry), 10);
    g_signal_connect (G_OBJECT(entry), "changed", G_CALLBACK (get_entry_text6), strCallBack3);

    button = gtk_button_new_with_label("Ubah");
    gtk_grid_attach(GTK_GRID(grid3), button, 1, 7, 1, 1);
    gtk_widget_set_halign(button, GTK_ALIGN_CENTER);
    g_signal_connect (G_OBJECT(button), "clicked", G_CALLBACK (on_button_clicked), strCallBack3);

    strCallBack3->labelOutput = gtk_label_new("Lengkapi data pasien terlebih dahulu");
    gtk_grid_attach(GTK_GRID(grid3), strCallBack3->labelOutput, 1, 8, 1, 1);
    gtk_widget_set_halign(strCallBack3->labelOutput, GTK_ALIGN_CENTER);
    gtk_widget_set_margin_start(strCallBack3->labelOutput, 10);
    

    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(set_label_text), strCallBack3);
    }

    //Page 4 (Hapus data pasien)
    {
    strCallbackData *strCallBack4 = g_new0(strCallbackData, 1);

    grid4 = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(grid4), 10);
    gtk_grid_set_column_spacing(GTK_GRID(grid4), 10);
    page4 = gtk_stack_add_child(GTK_STACK(stack), grid4);
    gtk_stack_page_set_title(GTK_STACK_PAGE(page4), "Hapus data pasien");

    label = gtk_label_new("Masukkan ID pasien yang ingin dihapus.");
    gtk_grid_attach(GTK_GRID(grid4), label, 0, 0, 2, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_START);
    gtk_widget_set_margin_start(label, 10);

    label = gtk_label_new("ID pasien\t\t: ");
    gtk_grid_attach(GTK_GRID(grid4), label, 0, 1, 1, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_START);
    gtk_widget_set_margin_start(label, 10);

    entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid4), entry, 1, 1, 2, 1);
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry), "KX 1234567");
    gtk_widget_set_hexpand(GTK_WIDGET(entry), TRUE);
    gtk_widget_set_margin_end(GTK_WIDGET(entry), 10);
    g_signal_connect (G_OBJECT(entry), "changed", G_CALLBACK (get_entry_text1), strCallBack4);

    button = gtk_button_new_with_label("Hapus");
    gtk_grid_attach(GTK_GRID(grid4), button, 1, 2, 1, 1);
    gtk_widget_set_halign(button, GTK_ALIGN_CENTER);
    g_signal_connect (G_OBJECT(button), "clicked", G_CALLBACK (on_button_clicked), strCallBack4);

    strCallBack4->labelOutput = gtk_label_new("Lengkapi data pasien terlebih dahulu");
    gtk_grid_attach(GTK_GRID(grid4), strCallBack4->labelOutput, 1, 3, 1, 1);
    gtk_widget_set_halign(strCallBack4->labelOutput, GTK_ALIGN_CENTER);
    gtk_widget_set_margin_start(strCallBack4->labelOutput, 10);
    
    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(set_label_text), strCallBack4);
    }

    //Page 5 (Cari data pasien)
    {
    strCallbackData *strCallBack5 = g_new0(strCallbackData, 1);

    grid5 = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(grid5), 10);
    gtk_grid_set_column_spacing(GTK_GRID(grid5), 10);
    page5 = gtk_stack_add_child(GTK_STACK(stack), grid5);
    gtk_stack_page_set_title(GTK_STACK_PAGE(page5), "Cari data pasien");

    label = gtk_label_new("Masukkan ID pasien yang ingin dicari.");
    gtk_grid_attach(GTK_GRID(grid5), label, 0, 0, 3, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_START);
    gtk_widget_set_margin_start(label, 10);

    label = gtk_label_new("ID pasien\t\t: ");
    gtk_grid_attach(GTK_GRID(grid5), label, 0, 1, 1, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_START);
    gtk_widget_set_margin_start(label, 10);

    entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid5), entry, 1, 1, 2, 1);
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry), "KX 1234567");
    gtk_widget_set_hexpand(GTK_WIDGET(entry), TRUE);
    gtk_widget_set_margin_end(GTK_WIDGET(entry), 10);
    g_signal_connect (G_OBJECT(entry), "changed", G_CALLBACK (get_entry_text1), strCallBack5);

    button = gtk_button_new_with_label("Cari");
    gtk_grid_attach(GTK_GRID(grid5), button, 1, 2, 1, 1);
    gtk_widget_set_halign(button, GTK_ALIGN_CENTER);
    g_signal_connect (G_OBJECT(button), "clicked", G_CALLBACK (on_button_clicked), strCallBack5);

    strCallBack5->labelOutput = gtk_label_new("Lengkapi data pasien terlebih dahulu");
    gtk_grid_attach(GTK_GRID(grid5), strCallBack5->labelOutput, 0, 3, 1, 1);
    gtk_widget_set_halign(strCallBack5->labelOutput, GTK_ALIGN_START);
    gtk_widget_set_margin_start(strCallBack5->labelOutput, 10);
    
    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(set_label_text), strCallBack5);
    }

    //Page 6 (Tambah riwayat medis pasien)
    {
    strCallbackData *strCallBack6 = g_new0(strCallbackData, 1);

    grid6 = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(grid6), 10);
    gtk_grid_set_column_spacing(GTK_GRID(grid6), 10);
    page6 = gtk_stack_add_child(GTK_STACK(stack), grid6);
    gtk_stack_page_set_title(GTK_STACK_PAGE(page6), "Tambah riwayat medis pasien");

    label = gtk_label_new("Masukkan ID pasien yang ingin ditambahkan riwayat medis.");
    gtk_grid_attach(GTK_GRID(grid6), label, 0, 0, 3, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_START);
    gtk_widget_set_margin_start(label, 10);

    label = gtk_label_new("ID pasien\t\t: ");
    gtk_grid_attach(GTK_GRID(grid6), label, 0, 1, 1, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_START);
    gtk_widget_set_margin_start(label, 10);

    entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid6), entry, 1, 1, 2, 1);
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry), "KX 1234567");
    gtk_widget_set_hexpand(GTK_WIDGET(entry), TRUE);
    gtk_widget_set_margin_end(GTK_WIDGET(entry), 10);
    g_signal_connect (G_OBJECT(entry), "changed", G_CALLBACK (get_entry_text1), strCallBack6);

    label = gtk_label_new("Tanggal kunjungan\t: ");
    gtk_grid_attach(GTK_GRID(grid6), label, 0, 2, 1, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_START);
    gtk_widget_set_margin_start(label, 10);

    entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid6), entry, 1, 2, 2, 1);
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry), "Tanggal-bulan-tahun");
    gtk_widget_set_hexpand(GTK_WIDGET(entry), TRUE);
    gtk_widget_set_margin_end(GTK_WIDGET(entry), 10);
    g_signal_connect (G_OBJECT(entry), "changed", G_CALLBACK (get_entry_text2), strCallBack6);

    label = gtk_label_new("Diagnosis\t\t: ");
    gtk_grid_attach(GTK_GRID(grid6), label, 0, 3, 1, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_START);
    gtk_widget_set_margin_start(label, 10);

    entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid6), entry, 1, 3, 2, 1);
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry), "Dehidrasi");
    gtk_widget_set_hexpand(GTK_WIDGET(entry), TRUE);
    gtk_widget_set_margin_end(GTK_WIDGET(entry), 10);
    g_signal_connect (G_OBJECT(entry), "changed", G_CALLBACK (get_entry_text3), strCallBack6);

    label = gtk_label_new("Tindakan\t\t\t: ");
    gtk_grid_attach(GTK_GRID(grid6), label, 0, 4, 1, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_START);
    gtk_widget_set_margin_start(label, 10);

    entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid6), entry, 1, 4, 2, 1);
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry), "Vaksinasi");
    gtk_widget_set_hexpand(GTK_WIDGET(entry), TRUE);
    gtk_widget_set_margin_end(GTK_WIDGET(entry), 10);
    g_signal_connect (G_OBJECT(entry), "changed", G_CALLBACK (get_entry_text4), strCallBack6);

    label = gtk_label_new("Jadwal kontrol\t: ");
    gtk_grid_attach(GTK_GRID(grid6), label, 0, 5, 1, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_START);
    gtk_widget_set_margin_start(label, 10);

    entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid6), entry, 1, 5, 2, 1);
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry), "Tanggal-bulan-tahun");
    gtk_widget_set_hexpand(GTK_WIDGET(entry), TRUE);
    gtk_widget_set_margin_end(GTK_WIDGET(entry), 10);
    g_signal_connect (G_OBJECT(entry), "changed", G_CALLBACK (get_entry_text5), strCallBack6);

    button = gtk_button_new_with_label("Tambahkan");
    gtk_grid_attach(GTK_GRID(grid6), button, 1, 6, 1, 1);
    gtk_widget_set_halign(button, GTK_ALIGN_END);
    g_signal_connect (G_OBJECT(button), "clicked", G_CALLBACK (on_button_clicked), strCallBack6);

    strCallBack6->labelOutput = gtk_label_new("Lengkapi data pasien terlebih dahulu.");
    gtk_grid_attach(GTK_GRID(grid6), strCallBack6->labelOutput, 1, 7, 1, 1);
    gtk_widget_set_halign(strCallBack6->labelOutput, GTK_ALIGN_CENTER);
    gtk_widget_set_margin_start(strCallBack6->labelOutput, 10);
    
    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(set_label_text), strCallBack6);
    }
    
    //Page 7 (Ubah riwayat medis pasien)
    {
    strCallbackData *strCallBack7 = g_new0(strCallbackData, 1);

    grid7 = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(grid7), 10);
    gtk_grid_set_column_spacing(GTK_GRID(grid7), 10);
    page7 = gtk_stack_add_child(GTK_STACK(stack), grid7);
    gtk_stack_page_set_title(GTK_STACK_PAGE(page7), "Ubah riwayat medis pasien");

    label = gtk_label_new("Masukkan data pasien yang ingin diubah riwayat medis.");
    gtk_grid_attach(GTK_GRID(grid7), label, 0, 0, 3, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_START);
    gtk_widget_set_margin_start(label, 10);

    label = gtk_label_new("ID lama pasien\t\t\t: ");
    gtk_grid_attach(GTK_GRID(grid7), label, 0, 1, 1, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_START);
    gtk_widget_set_margin_start(label, 10);

    entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid7), entry, 1, 1, 2, 1);
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry), "KX 1234567");
    gtk_widget_set_hexpand(GTK_WIDGET(entry), TRUE);
    gtk_widget_set_margin_end(GTK_WIDGET(entry), 10);
    g_signal_connect (G_OBJECT(entry), "changed", G_CALLBACK (get_entry_text1), strCallBack7);

    label = gtk_label_new("ID baru pasien\t\t\t: ");
    gtk_grid_attach(GTK_GRID(grid7), label, 0, 2, 1, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_START);
    gtk_widget_set_margin_start(label, 10);

    entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid7), entry, 1, 2, 2, 1);
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry), "Contoh: KX 1234567");
    gtk_widget_set_hexpand(GTK_WIDGET(entry), TRUE);
    gtk_widget_set_margin_end(GTK_WIDGET(entry), 10);
    g_signal_connect (G_OBJECT(entry), "changed", G_CALLBACK (get_entry_text2), strCallBack7);

    label = gtk_label_new("Tanggal kunjungan lama\t: ");
    gtk_grid_attach(GTK_GRID(grid7), label, 0, 3, 1, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_START);
    gtk_widget_set_margin_start(label, 10);

    entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid7), entry, 1, 3, 2, 1);
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry), "Tanggal-bulan-tahun");
    gtk_widget_set_hexpand(GTK_WIDGET(entry), TRUE);
    gtk_widget_set_margin_end(GTK_WIDGET(entry), 10);
    g_signal_connect (G_OBJECT(entry), "changed", G_CALLBACK (get_entry_text3), strCallBack7);
    
    label = gtk_label_new("Tanggal kunjungan baru\t: ");
    gtk_grid_attach(GTK_GRID(grid7), label, 0, 4, 1, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_START);
    gtk_widget_set_margin_start(label, 10);

    entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid7), entry, 1, 4, 2, 1);
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry), "Tanggal-bulan-tahun");
    gtk_widget_set_hexpand(GTK_WIDGET(entry), TRUE);
    gtk_widget_set_margin_end(GTK_WIDGET(entry), 10);
    g_signal_connect (G_OBJECT(entry), "changed", G_CALLBACK (get_entry_text4), strCallBack7);

    label = gtk_label_new("Diagnosis\t\t\t\t: ");
    gtk_grid_attach(GTK_GRID(grid7), label, 0, 5, 1, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_START);
    gtk_widget_set_margin_start(label, 10);

    entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid7), entry, 1, 5, 2, 1);
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry), "Dehidrasi");
    gtk_widget_set_hexpand(GTK_WIDGET(entry), TRUE);
    gtk_widget_set_margin_end(GTK_WIDGET(entry), 10);
    g_signal_connect (G_OBJECT(entry), "changed", G_CALLBACK (get_entry_text5), strCallBack7);

    label = gtk_label_new("Tindakan\t\t\t\t\t: ");
    gtk_grid_attach(GTK_GRID(grid7), label, 0, 6, 1, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_START);
    gtk_widget_set_margin_start(label, 10);
    
    entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid7), entry, 1, 6, 2, 1);
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry), "Vaksinasi");
    gtk_widget_set_hexpand(GTK_WIDGET(entry), TRUE);
    gtk_widget_set_margin_end(GTK_WIDGET(entry), 10);
    g_signal_connect (G_OBJECT(entry), "changed", G_CALLBACK (get_entry_text6), strCallBack7);

    button = gtk_button_new_with_label("Ubah");
    gtk_grid_attach(GTK_GRID(grid7), button, 1, 7, 1, 1);
    gtk_widget_set_halign(button, GTK_ALIGN_END);
    g_signal_connect (G_OBJECT(button), "clicked", G_CALLBACK (on_button_clicked), strCallBack7);

    strCallBack7->labelOutput = gtk_label_new("Lengkapi data pasien terlebih dahulu");
    gtk_grid_attach(GTK_GRID(grid7), strCallBack7->labelOutput, 1, 8, 1, 1);
    gtk_widget_set_halign(strCallBack7->labelOutput, GTK_ALIGN_CENTER);
    gtk_widget_set_margin_start(strCallBack7->labelOutput, 10);
    
    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(set_label_text), strCallBack7);
    }

    //Page 8 (Hapus riwayat medis pasien)
    {
    strCallbackData *strCallBack8 = g_new0(strCallbackData, 1);

    grid8 = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(grid8), 10);
    gtk_grid_set_column_spacing(GTK_GRID(grid8), 10);
    page8 = gtk_stack_add_child(GTK_STACK(stack), grid8);
    gtk_stack_page_set_title(GTK_STACK_PAGE(page8), "Hapus riwayat medis pasien");

    label = gtk_label_new("Masukkan data pasien yang ingin dihapus riwayat medis.");
    gtk_grid_attach(GTK_GRID(grid8), label, 0, 0, 3, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_START);
    gtk_widget_set_margin_start(label, 10);

    label = gtk_label_new("ID pasien\t\t: ");
    gtk_grid_attach(GTK_GRID(grid8), label, 0, 1, 1, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_START);
    gtk_widget_set_margin_start(label, 10);

    entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid8), entry, 1, 1, 2, 1);
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry), "KX 1234567");
    gtk_widget_set_hexpand(GTK_WIDGET(entry), TRUE);
    gtk_widget_set_margin_end(GTK_WIDGET(entry), 10);
    g_signal_connect (G_OBJECT(entry), "changed", G_CALLBACK (get_entry_text1), strCallBack8);
    
    label = gtk_label_new("Tanggal kunjungan\t: ");
    gtk_grid_attach(GTK_GRID(grid8), label, 0, 2, 1, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_START);
    gtk_widget_set_margin_start(label, 10);

    entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid8), entry, 1, 2, 2, 1);
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry), "Tanggal-bulan-tahun");
    gtk_widget_set_hexpand(GTK_WIDGET(entry), TRUE);
    gtk_widget_set_margin_end(GTK_WIDGET(entry), 10);
    g_signal_connect (G_OBJECT(entry), "changed", G_CALLBACK (get_entry_text2), strCallBack8);

    button = gtk_button_new_with_label("Hapus");
    gtk_grid_attach(GTK_GRID(grid8), button, 1, 3, 1, 1);
    gtk_widget_set_halign(button, GTK_ALIGN_END);
    g_signal_connect (G_OBJECT(button), "clicked", G_CALLBACK (on_button_clicked), strCallBack8);

    strCallBack8->labelOutput = gtk_label_new("Lengkapi data pasien terlebih dahulu");
    gtk_grid_attach(GTK_GRID(grid8), strCallBack8->labelOutput, 1, 4, 1, 1);
    gtk_widget_set_halign(strCallBack8->labelOutput, GTK_ALIGN_CENTER);
    gtk_widget_set_margin_start(strCallBack8->labelOutput, 10);
    
    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(set_label_text), strCallBack8);
    }
    
    //Page 9 (Cari riwayat medis pasien)
    {
    strCallbackData *strCallBack9 = g_new0(strCallbackData, 1);

    grid9 = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(grid9), 10);
    gtk_grid_set_column_spacing(GTK_GRID(grid9), 10);
    page9 = gtk_stack_add_child(GTK_STACK(stack), grid9);
    gtk_stack_page_set_title(GTK_STACK_PAGE(page9), "Cari riwayat medis pasien");

    label = gtk_label_new("Masukkan data pasien yang ingin dicari riwayat medis.");
    gtk_grid_attach(GTK_GRID(grid9), label, 0, 0, 3, 1);
    gtk_widget_set_margin_start(label, 10);
    gtk_widget_set_halign(label, GTK_ALIGN_START);
    gtk_widget_set_margin_start(label, 10);

    label = gtk_label_new("ID pasien\t\t: ");
    gtk_grid_attach(GTK_GRID(grid9), label, 0, 1, 1, 1);
    gtk_widget_set_margin_start(label, 10);
    gtk_widget_set_halign(label, GTK_ALIGN_START);
    gtk_widget_set_margin_start(label, 10);

    entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid9), entry, 1, 1, 2, 1);
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry), "KX 1234567");
    gtk_widget_set_hexpand(GTK_WIDGET(entry), TRUE);
    gtk_widget_set_margin_end(GTK_WIDGET(entry), 10);
    g_signal_connect (G_OBJECT(entry), "changed", G_CALLBACK (get_entry_text1), strCallBack9);

    label = gtk_label_new("Tanggal kunjungan\t: ");
    gtk_grid_attach(GTK_GRID(grid9), label, 0, 2, 1, 1);
    gtk_widget_set_margin_start(label, 10);
    gtk_widget_set_halign(label, GTK_ALIGN_START);
    gtk_widget_set_margin_start(label, 10);

    entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid9), entry, 1, 2, 2, 1);
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry), "Tanggal-bulan-tahun");
    gtk_widget_set_hexpand(GTK_WIDGET(entry), TRUE);
    gtk_widget_set_margin_end(GTK_WIDGET(entry), 10);
    g_signal_connect (G_OBJECT(entry), "changed", G_CALLBACK (get_entry_text2), strCallBack9);

    button = gtk_button_new_with_label("Cari");
    gtk_grid_attach(GTK_GRID(grid9), button, 1, 3, 1, 1);
    gtk_widget_set_halign(button, GTK_ALIGN_END);
    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK (on_button_clicked), strCallBack9);

    strCallBack9->labelOutput = gtk_label_new("Riwayat medis\t: ");
    gtk_grid_attach(GTK_GRID(grid9), strCallBack9->labelOutput, 0, 4, 1, 1);
    gtk_widget_set_halign(strCallBack9->labelOutput, GTK_ALIGN_START);
    gtk_widget_set_margin_start(strCallBack9->labelOutput, 10);

    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(set_label_text), strCallBack9);
    }

    //Page 10 (Kirim data dan riwayat medis pasien ke petugas medis)
    {
    strCallbackData *strCallBack10 = g_new0(strCallbackData, 1);

    grid10 = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(grid10), 10);
    gtk_grid_set_column_spacing(GTK_GRID(grid10), 10);
    page10 = gtk_stack_add_child(GTK_STACK(stack), grid10);
    gtk_stack_page_set_title(GTK_STACK_PAGE(page10), "Kirim data dan riwayat medis pasien ke petugas medis");

    label = gtk_label_new("Masukkan ID pasien yang ingin dikirim ke petugas medis.");
    gtk_grid_attach(GTK_GRID(grid10), label, 0, 0, 3, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_START);
    gtk_widget_set_margin_start(label, 10);

    label = gtk_label_new("ID pasien\t\t\t: ");
    gtk_grid_attach(GTK_GRID(grid10), label, 0, 1, 1, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_START);
    gtk_widget_set_margin_start(label, 10);

    entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid10), entry, 1, 1, 2, 1);
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry), "KX 1234567");
    gtk_widget_set_hexpand(GTK_WIDGET(entry), TRUE);
    gtk_widget_set_margin_end(GTK_WIDGET(entry), 10);
    g_signal_connect (G_OBJECT(entry), "changed", G_CALLBACK (get_entry_text1), strCallBack10);

    button = gtk_button_new_with_label("Kirim");
    gtk_grid_attach(GTK_GRID(grid10), button, 1, 2, 1, 1);
    gtk_widget_set_halign(button, GTK_ALIGN_END);
    g_signal_connect (G_OBJECT(button), "clicked", G_CALLBACK (on_button_clicked), strCallBack10);

    strCallBack10->labelOutput = gtk_label_new("Riwayat medis\t\t: ");
    gtk_grid_attach(GTK_GRID(grid10), strCallBack10->labelOutput, 0, 3, 1, 1);
    gtk_widget_set_halign(strCallBack10->labelOutput, GTK_ALIGN_START);
    gtk_widget_set_margin_start(strCallBack10->labelOutput, 10);

    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(set_label_text), strCallBack10);
    }

    //Page 11 (Akses laporan keuangan)
    {
    strCallbackData *strCallBack11 = g_new0(strCallbackData, 1);
    strCallBack11->str1 = "Test laporan keuangan";

    grid11 = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(grid11), 10);
    gtk_grid_set_column_spacing(GTK_GRID(grid11), 10);
    page11 = gtk_stack_add_child(GTK_STACK(stack), grid11);
    gtk_stack_page_set_title(GTK_STACK_PAGE(page11), "Akses laporan keuangan");

    label = gtk_label_new("Laporan keuangan Klinik X");
    gtk_grid_attach(GTK_GRID(grid11), label, 0, 0, 1, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_START);
    gtk_widget_set_margin_start(label, 10);

    button = gtk_button_new_with_label("Cetak/refresh laporan keuangan");
    gtk_grid_attach(GTK_GRID(grid11), button, 0, 1, 1, 1);
    gtk_widget_set_halign(button, GTK_ALIGN_START);
    gtk_widget_set_margin_start(button, 10);

    strCallBack11->labelOutput = gtk_label_new("Data laporan keuangan");
    gtk_grid_attach(GTK_GRID(grid11), strCallBack11->labelOutput, 0, 2, 3, 1);
    gtk_widget_set_hexpand(GTK_WIDGET(strCallBack11->labelOutput), TRUE);
    gtk_widget_set_vexpand(GTK_WIDGET(strCallBack11->labelOutput), TRUE);

    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(set_label_text), strCallBack11);
    }

    //Page 12 (Statistik riwayat medis)
    {
    strCallbackData *strCallBack12 = g_new0(strCallbackData, 1);
    strCallBack12->str1 = "Test riwayat medis";

    grid12 = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(grid12), 10);
    gtk_grid_set_column_spacing(GTK_GRID(grid12), 10);
    page12 = gtk_stack_add_child(GTK_STACK(stack), grid12);
    gtk_stack_page_set_title(GTK_STACK_PAGE(page12), "Statistik riwayat medis");

    label = gtk_label_new("Statistik riwayat medis");
    gtk_grid_attach(GTK_GRID(grid12), label, 0, 0, 1, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_START);
    gtk_widget_set_margin_start(label, 10);

    button = gtk_button_new_with_label("Cetak/refresh statistik riwayat medis");
    gtk_grid_attach(GTK_GRID(grid12), button, 0, 1, 1, 1);
    gtk_widget_set_halign(button, GTK_ALIGN_START);
    gtk_widget_set_margin_start(button, 10);

    strCallBack12->labelOutput = gtk_label_new("Data riwayat medis");
    gtk_grid_attach(GTK_GRID(grid12), strCallBack12->labelOutput, 0, 2, 3, 1);
    gtk_widget_set_hexpand(GTK_WIDGET(strCallBack12->labelOutput), TRUE);
    gtk_widget_set_vexpand(GTK_WIDGET(strCallBack12->labelOutput), TRUE);

    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(set_label_text), strCallBack12);
    }

    //Page 13 (Informasi jadwal kontrol pasien)
    {
    strCallbackData *strCallBack13 = g_new0(strCallbackData, 1);
    strCallBack13->str1 = "Test jadwal kontrol pasien";

    grid13 = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(grid13), 10);
    gtk_grid_set_column_spacing(GTK_GRID(grid13), 10);
    page13 = gtk_stack_add_child(GTK_STACK(stack), grid13);
    gtk_stack_page_set_title(GTK_STACK_PAGE(page13), "Informasi jadwal kontrol pasien");

    label = gtk_label_new("Masukkan bulan jadwal kontrol pasien");
    gtk_grid_attach(GTK_GRID(grid13), label, 0, 0, 3, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_START);
    gtk_widget_set_margin_start(label, 10);

    label = gtk_label_new("Bulan\t\t\t: ");
    gtk_grid_attach(GTK_GRID(grid13), label, 0, 1, 1, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_START);
    gtk_widget_set_margin_start(label, 10);
    
    entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid13), entry, 1, 1, 2, 1);
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry), "Januari");
    gtk_widget_set_hexpand(GTK_WIDGET(entry), TRUE);
    gtk_widget_set_margin_end(GTK_WIDGET(entry), 10);
    g_signal_connect (G_OBJECT(entry), "changed", G_CALLBACK (get_entry_text1), strCallBack13);

    button = gtk_button_new_with_label("Cari");
    gtk_grid_attach(GTK_GRID(grid13), button, 1, 2, 1, 1);
    gtk_widget_set_halign(button, GTK_ALIGN_END);
    g_signal_connect (G_OBJECT(button), "clicked", G_CALLBACK (on_button_clicked), strCallBack13);

    strCallBack13->labelOutput = gtk_label_new("Jadwal kontrol\t: ");
    gtk_grid_attach(GTK_GRID(grid13), strCallBack13->labelOutput, 0, 3, 1, 1);
    gtk_widget_set_halign(strCallBack13->labelOutput, GTK_ALIGN_START);
    gtk_widget_set_margin_start(strCallBack13->labelOutput, 10);

    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(set_label_text), strCallBack13);
    }

}

int main(int argc, char *argv[]) {
    GtkApplication *app;
    GtkWidget *window, *sidebar, *stack, *box, *widget, *header;
    int status;

    dataPasienHead = (dataPasien*) malloc(sizeof(dataPasien));
    //dataPasienHead->nama = NULL;

    riwayatDiagnosisHead = (riwayatDiagnosis*) malloc(sizeof(riwayatDiagnosis));

    readFile();     // baca csv
    
    app = gtk_application_new ("test.stackSideBar", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
    status = g_application_run (G_APPLICATION (app), argc, argv);
    writeFile();
    g_object_unref (app);
    return status;
}

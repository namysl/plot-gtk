#include <gtk/gtk.h>

GtkWidget *window;

GdkPixbuf *create_pixbuf(const gchar *filename) {
    //wczytywanie obrazow
    GdkPixbuf *pixbuf;
    GError *error = NULL;
    pixbuf = gdk_pixbuf_new_from_file(filename, &error);

    if (!pixbuf){
        fprintf(stderr, "%s\n", error->message);
        g_error_free(error);
    }
    return pixbuf;
}


void plot_linear(GtkWindow *parent, gpointer data){
    //wykres dla funkcji liniowej
    parent = GTK_WINDOW(window);

    GtkWidget *content_area;
    GtkWidget *dialog;
    GtkWidget *hbox;
    GtkWidget *table;

    GtkWidget *label;
    GtkWidget *slope, *y_intercept, *x_min, *x_max, *step;  //a, b
    GtkAdjustment *adjustment; //adjustment -> startval, minval, maxval, step increment, page increment, page size
    
    gint response;

    GtkDialogFlags flags = GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT;

    dialog = gtk_dialog_new_with_buttons("Wykres funkcji liniowej", parent,
                                         flags,
                                         ("OK"), GTK_RESPONSE_OK,
                                         "Anuluj", GTK_RESPONSE_CANCEL,
                                          NULL);

    gtk_window_set_transient_for(GTK_WINDOW(dialog), parent);
    content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));

    hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
    gtk_container_set_border_width(GTK_CONTAINER(hbox), 30);

    gtk_box_pack_start(GTK_BOX(content_area), hbox, FALSE, FALSE, 0);

    table = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(table), 20); //odleglosc od obiektow wierszami
    gtk_grid_set_column_spacing(GTK_GRID(table), 25); //kolumnami
    gtk_box_pack_start(GTK_BOX(hbox), table, TRUE, TRUE, 0);

    //pola
    adjustment = gtk_adjustment_new(0, -10000, 10000, 1, 1, 1);
    label = gtk_label_new("Współczynnik kierunkowy (a):");
    gtk_grid_attach(GTK_GRID(table), label, 0, 0, 1, 1);
    slope = gtk_spin_button_new(adjustment, 5, 2);  //adjustment, climb_rate, digits
    gtk_grid_attach(GTK_GRID(table), slope, 1, 0, 4, 1);

    adjustment = gtk_adjustment_new(0, -10000, 10000, 1, 1, 1);
    label = gtk_label_new("Wyraz wolny (b):");
    gtk_grid_attach(GTK_GRID(table), label, 0, 1, 1, 1);
    y_intercept = gtk_spin_button_new(adjustment, 5, 2);
    gtk_grid_attach(GTK_GRID(table), y_intercept, 1, 1, 4, 1);

    adjustment = gtk_adjustment_new(0, -10000, 10000, 1, 1, 1);
    label = gtk_label_new("Dolny zakres na osi x:");
    gtk_grid_attach(GTK_GRID(table), label, 0, 2, 1, 1);
    x_min = gtk_spin_button_new(adjustment, 5, 2);
    gtk_grid_attach(GTK_GRID(table), x_min, 1, 2, 4, 1);
    
    adjustment = gtk_adjustment_new(0, -10000, 10000, 1, 1, 1);
    label = gtk_label_new("Górny zakres na osi x:");
    gtk_grid_attach(GTK_GRID(table), label, 0, 3, 1, 1);
    x_max = gtk_spin_button_new(adjustment, 5, 2);
    gtk_grid_attach(GTK_GRID(table), x_max, 1, 3, 4, 1);
    
    adjustment = gtk_adjustment_new(1, 0, 10000, 1, 1, 1);
    label = gtk_label_new("Wielkość kroku:");
    gtk_grid_attach(GTK_GRID(table), label, 0, 4, 1, 1);
    step = gtk_spin_button_new(adjustment, 5, 2);
    gtk_grid_attach(GTK_GRID(table), step, 1, 4, 4, 1);

    gtk_widget_show_all(hbox);
    response = gtk_dialog_run(GTK_DIALOG(dialog));

    gtk_widget_destroy(dialog);
}


void plot_quadratic(GtkWindow *parent, gpointer data){
    //wykres dla funkcji liniowej
    parent = GTK_WINDOW(window);

    GtkWidget *content_area;
    GtkWidget *dialog;
    GtkWidget *hbox;
    GtkWidget *table;

    GtkWidget *label;
    GtkWidget *a, *b, *c, *x_min, *x_max, *step;
    GtkAdjustment *adjustment;
    
    gint response;

    GtkDialogFlags flags = GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT;

    dialog = gtk_dialog_new_with_buttons("Wykres funkcji kwadratowej", parent,
                                         flags,
                                         ("OK"), GTK_RESPONSE_OK,
                                         "Anuluj", GTK_RESPONSE_CANCEL,
                                          NULL);

    gtk_window_set_transient_for(GTK_WINDOW(dialog), parent);
    content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));

    hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
    gtk_container_set_border_width(GTK_CONTAINER(hbox), 30);

    gtk_box_pack_start(GTK_BOX(content_area), hbox, FALSE, FALSE, 0);

    table = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(table), 20); //odleglosc od obiektow wierszami
    gtk_grid_set_column_spacing(GTK_GRID(table), 25); //kolumnami
    gtk_box_pack_start(GTK_BOX(hbox), table, TRUE, TRUE, 0);

    //pola
    adjustment = gtk_adjustment_new(0, -10000, 10000, 1, 1, 1);
    label = gtk_label_new("Wartość a:");
    gtk_grid_attach(GTK_GRID(table), label, 0, 0, 1, 1);
    a = gtk_spin_button_new(adjustment, 5, 2);  //adjustment, climb_rate, digits
    gtk_grid_attach(GTK_GRID(table), a, 1, 0, 4, 1);

    adjustment = gtk_adjustment_new(0, -10000, 10000, 1, 1, 1);
    label = gtk_label_new("Wartość b:");
    gtk_grid_attach(GTK_GRID(table), label, 0, 1, 1, 1);
    b = gtk_spin_button_new(adjustment, 5, 2);
    gtk_grid_attach(GTK_GRID(table), b, 1, 1, 4, 1);
    
    adjustment = gtk_adjustment_new(0, -10000, 10000, 1, 1, 1);
    label = gtk_label_new("Wartość c:");
    gtk_grid_attach(GTK_GRID(table), label, 0, 2, 1, 1);
    c = gtk_spin_button_new(adjustment, 5, 2);
    gtk_grid_attach(GTK_GRID(table), c, 1, 2, 4, 1);

    adjustment = gtk_adjustment_new(0, -10000, 10000, 1, 1, 1);
    label = gtk_label_new("Dolny zakres na osi x:");
    gtk_grid_attach(GTK_GRID(table), label, 0, 3, 1, 1);
    x_min = gtk_spin_button_new(adjustment, 5, 2);
    gtk_grid_attach(GTK_GRID(table), x_min, 1, 3, 4, 1);
    
    adjustment = gtk_adjustment_new(0, -10000, 10000, 1, 1, 1);
    label = gtk_label_new("Górny zakres na osi x:");
    gtk_grid_attach(GTK_GRID(table), label, 0, 4, 1, 1);
    x_max = gtk_spin_button_new(adjustment, 5, 2);
    gtk_grid_attach(GTK_GRID(table), x_max, 1, 4, 4, 1);
    
    adjustment = gtk_adjustment_new(1, 0, 10000, 1, 1, 1);
    label = gtk_label_new("Wielkość kroku:");
    gtk_grid_attach(GTK_GRID(table), label, 0, 5, 1, 1);
    step = gtk_spin_button_new(adjustment, 5, 2);
    gtk_grid_attach(GTK_GRID(table), step, 1, 5, 4, 1);

    gtk_widget_show_all(hbox);
    response = gtk_dialog_run(GTK_DIALOG(dialog));

    gtk_widget_destroy(dialog);
}

void plot_binomial_dist(GtkWindow *parent, gpointer data){
    //wykres dla funkcji liniowej
    parent = GTK_WINDOW(window);

    GtkWidget *content_area;
    GtkWidget *dialog;
    GtkWidget *hbox;
    GtkWidget *table;

    GtkWidget *label;
    GtkWidget *n, *p;
    GtkAdjustment *adjustment;
    
    gint response;

    GtkDialogFlags flags = GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT;

    dialog = gtk_dialog_new_with_buttons("Wykres rozkładu dwumianowego", parent,
                                         flags,
                                         ("OK"), GTK_RESPONSE_OK,
                                         "Anuluj", GTK_RESPONSE_CANCEL,
                                          NULL);

    gtk_window_set_transient_for(GTK_WINDOW(dialog), parent);
    content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));

    hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
    gtk_container_set_border_width(GTK_CONTAINER(hbox), 30);

    gtk_box_pack_start(GTK_BOX(content_area), hbox, FALSE, FALSE, 0);

    table = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(table), 20); //odleglosc od obiektow wierszami
    gtk_grid_set_column_spacing(GTK_GRID(table), 25); //kolumnami
    gtk_box_pack_start(GTK_BOX(hbox), table, TRUE, TRUE, 0);

    //pola
    adjustment = gtk_adjustment_new(0, 1, 10000, 1, 1, 1);
    label = gtk_label_new("Liczba prób (n):");
    gtk_grid_attach(GTK_GRID(table), label, 0, 0, 1, 1);
    n = gtk_spin_button_new(adjustment, 5, 2);  //adjustment, climb_rate, digits
    gtk_grid_attach(GTK_GRID(table), n, 1, 0, 4, 1);

    adjustment = gtk_adjustment_new(0, 0, 1.1, 0.1, 0.1, 0.1);
    label = gtk_label_new("Prawdopodobieństwo sukcesu w próbie (p):");
    gtk_grid_attach(GTK_GRID(table), label, 0, 1, 1, 1);
    p = gtk_spin_button_new(adjustment, 5, 2);
    gtk_grid_attach(GTK_GRID(table), p, 1, 1, 4, 1);

    gtk_widget_show_all(hbox);
    response = gtk_dialog_run(GTK_DIALOG(dialog));

    gtk_widget_destroy(dialog);
}



void show_plot_toolb(GtkWindow *parent, gpointer data){
    //wykresy popup
    parent = GTK_WINDOW(window);

    GtkWidget *content_area;
    GtkWidget *dialog;
    GtkWidget *hbox;
    GtkWidget *table;

    GtkWidget *button_linear, *button_quadratic, *button_binomial;
  
    gint response;

    GtkDialogFlags flags = GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT;

    dialog = gtk_dialog_new_with_buttons("Wykres funkcji", parent,
                                         flags,
                                         "Anuluj", GTK_RESPONSE_CANCEL,
                                          NULL);

    gtk_window_set_transient_for(GTK_WINDOW(dialog), parent);
    content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));

    hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
    gtk_container_set_border_width(GTK_CONTAINER(hbox), 30);

    gtk_box_pack_start(GTK_BOX(content_area), hbox, FALSE, FALSE, 0);

    table = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(table), 20); //odleglosc od obiektow wierszami
    gtk_grid_set_column_spacing(GTK_GRID(table), 25); //kolumnami
    gtk_box_pack_start(GTK_BOX(hbox), table, TRUE, TRUE, 0);

    //guziki
    button_linear = gtk_button_new_with_label("Funkcja liniowa");
    gtk_grid_attach(GTK_GRID(table), button_linear, 0, 0, 1, 1);
    gtk_widget_set_size_request(button_linear, 100, 30);

    button_quadratic = gtk_button_new_with_label("Funkcja kwadratowa");
    gtk_grid_attach(GTK_GRID(table), button_quadratic, 0, 1, 1, 1);
    gtk_widget_set_size_request(button_quadratic, 100, 30);

    button_binomial = gtk_button_new_with_label("Rozkład dwumianowy");
    gtk_grid_attach(GTK_GRID(table), button_binomial, 0, 2, 1, 1);
    gtk_widget_set_size_request(button_binomial, 100, 30);

    //tutaj sygnaly dla guzikow
    g_signal_connect(button_linear, "clicked",
                     G_CALLBACK(plot_linear), NULL);
                      
    g_signal_connect(button_quadratic, "clicked",
                     G_CALLBACK(plot_quadratic), NULL);

    g_signal_connect(button_binomial, "clicked",
                     G_CALLBACK(plot_binomial_dist), NULL);
                      
    gtk_widget_show_all(hbox);
    response = gtk_dialog_run(GTK_DIALOG(dialog));

    gtk_widget_destroy(dialog);
}


void result_linear_eq(GtkWindow *parent, gpointer data){
	parent = GTK_WINDOW(window);

    GtkWidget *content_area;
    GtkWidget *dialog;
    GtkWidget *hbox;
    GtkWidget *table;
    GtkWidget *view;

    GtkTextBuffer *buffer;
    
    gint response;

    GtkDialogFlags flags = GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT;

    dialog = gtk_dialog_new_with_buttons("Rozwiązanie", parent,
                                         flags,
                                         ("Zamknij"), GTK_RESPONSE_CANCEL,
                                          NULL,
                                          NULL);

    gtk_window_set_transient_for(GTK_WINDOW(dialog), parent);
    content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));

    hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
    gtk_container_set_border_width(GTK_CONTAINER(hbox), 30);

    gtk_box_pack_start(GTK_BOX(content_area), hbox, FALSE, FALSE, 0);

    table = gtk_grid_new();
    gtk_box_pack_start(GTK_BOX(hbox), table, TRUE, TRUE, 0);

    //pola
	view = gtk_text_view_new();
	
	buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(view));
	gtk_text_view_set_editable(GTK_TEXT_VIEW(view), FALSE);
	gtk_text_buffer_set_text(buffer, "Tutaj rozwiązanie elo", -1);
	gtk_grid_attach(GTK_GRID(table), view, 0, 0, 1, 1);

    gtk_widget_show_all(hbox);
    response = gtk_dialog_run(GTK_DIALOG(dialog));

    gtk_widget_destroy(dialog);
}


void show_linear_eq_toolb(GtkWindow *parent, gpointer data){
    //rownania liniowe popup
    parent = GTK_WINDOW(window);

    GtkWidget *content_area;
    GtkWidget *dialog;
    GtkWidget *hbox;
    GtkWidget *table;
	GtkWidget *view;
    GtkWidget *label;
    GtkWidget *button_ok, *button_cancel;
    GtkTextBuffer *buffer;
    gint response;

    GtkDialogFlags flags = GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT;

    dialog = gtk_dialog_new_with_buttons("Rozwiąż równanie liniowe", parent,
                                         flags,
                                         NULL,
                                         NULL,
                                         NULL);

    gtk_window_set_transient_for(GTK_WINDOW(dialog), parent);
    content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));

    hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
    gtk_container_set_border_width(GTK_CONTAINER(hbox), 30);

    gtk_box_pack_start(GTK_BOX(content_area), hbox, FALSE, FALSE, 0);

    table = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(table), 20); //odleglosc od obiektow wierszami
    //gtk_grid_set_column_spacing(GTK_GRID(table), 25); //kolumnami
    gtk_box_pack_start(GTK_BOX(hbox), table, TRUE, TRUE, 0);

    label = gtk_label_new("Wprowadź równanie:");
    gtk_grid_attach(GTK_GRID(table), label, 0, 0, 1, 1);

	view = gtk_text_view_new();
	buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(view));
	gtk_text_view_set_editable(GTK_TEXT_VIEW(view), TRUE);
	gtk_grid_attach(GTK_GRID(table), view, 0, 1, 4, 1);
	
	button_ok = gtk_button_new_with_label("Rozwiąż");
    gtk_grid_attach(GTK_GRID(table), button_ok, 0, 2, 1, 1);

	g_signal_connect(button_ok, "clicked", G_CALLBACK(result_linear_eq), NULL);

    gtk_widget_show_all(hbox);
    response = gtk_dialog_run(GTK_DIALOG(dialog));
    
    gtk_widget_destroy(dialog);
}


int main(int argc, char *argv[]){
    GtkWidget *box;
    GtkWidget *toolbar;
    GtkWidget *label;
    
    GtkToolItem *linear_eq_toolb;
    GtkToolItem *plot_toolb;
    GtkToolItem *separator;
    GtkToolItem *info_toolb;

    GdkPixbuf *icon;


    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    //tytul na pasku okna
    gtk_window_set_title(GTK_WINDOW(window), "Plot GTK");
    //rozmiar i umiejscowienie okna programu
    gtk_window_set_default_size(GTK_WINDOW(window), 600, 300);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    //ikona programu
    icon = create_pixbuf("img/icon.jpg");
    gtk_window_set_icon(GTK_WINDOW(window), icon);

    //container dla paska narzedzi
    box = gtk_box_new(FALSE, 0);
    gtk_orientable_set_orientation(GTK_ORIENTABLE(box), GTK_ORIENTATION_VERTICAL);
    gtk_container_add(GTK_CONTAINER(window), box);
    toolbar = gtk_toolbar_new();
    //ikony i labele w toolbarze
    gtk_toolbar_set_style(GTK_TOOLBAR(toolbar), GTK_TOOLBAR_BOTH);

    //ROWNANIA LINIOWE
    linear_eq_toolb = gtk_tool_button_new(gtk_image_new_from_icon_name("accessories-calculator-symbolic",
                                    GTK_ICON_SIZE_SMALL_TOOLBAR), "Równania liniowe");
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), linear_eq_toolb, -1);

    //WYKRESY
    plot_toolb = gtk_tool_button_new(gtk_image_new_from_icon_name("input-tablet-symbolic",
                                     GTK_ICON_SIZE_SMALL_TOOLBAR), "Wykresy");
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), plot_toolb, -1);

    //separator
    separator = gtk_separator_tool_item_new();
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), separator, -1);

    //info
    info_toolb = gtk_tool_button_new(gtk_image_new_from_icon_name("dialog-information-symbolic",
                                     GTK_ICON_SIZE_SMALL_TOOLBAR), "info");
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), info_toolb, -1);
    gtk_tool_item_set_tooltip_markup(info_toolb, "Info");


    gtk_box_pack_start(GTK_BOX(box), toolbar, FALSE, FALSE, 5);

    //sygnały
    g_signal_connect(G_OBJECT(linear_eq_toolb), "clicked",
                     G_CALLBACK(show_linear_eq_toolb), NULL);
    
    g_signal_connect(G_OBJECT(plot_toolb), "clicked",
                     G_CALLBACK(show_plot_toolb), NULL);
    
    g_signal_connect(G_OBJECT(window), "destroy",
                     G_CALLBACK(gtk_main_quit), NULL);


    gtk_widget_show_all(window);
    g_object_unref(icon);
    gtk_main();

    return 0;
}

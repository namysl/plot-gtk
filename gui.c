#include <gtk/gtk.h>

GtkWidget *window, *treeview;

GdkPixbuf *create_pixbuf(const gchar *filename) {
    //wczytywanie obrazow dla ikon
    GdkPixbuf *pixbuf;
    GError *error = NULL;
    pixbuf = gdk_pixbuf_new_from_file(filename, &error);

    if (!pixbuf){
        fprintf(stderr, "%s\n", error->message);
        g_error_free(error);
    }
    return pixbuf;
}

int main(int argc, char *argv[]){
    GtkWidget *box;

    GtkWidget *toolbar;

    GtkToolItem *add_toolb;
    GtkToolItem *edit_toolb;
    GtkToolItem *delete_toolb;
    GtkToolItem *separator1;
    GtkToolItem *separator2;
    GtkToolItem *options_toolb;
    GtkToolItem *info_toolb;
    GtkToolItem *exit_toolb;

    GtkWidget *vbox;
    GtkWidget *sw;
    GtkWidget *label;

    GtkTreeModel *model;

    GdkPixbuf *icon;

    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    //tytul na pasku okna
    gtk_window_set_title(GTK_WINDOW(window), "Plot GTK");
    //rozmiar i umiejscowienie okna programu
    gtk_window_set_default_size(GTK_WINDOW(window), 1000, 700);
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

    //jakis wybor nr 1
    add_toolb = gtk_tool_button_new(gtk_image_new_from_icon_name("accessories-calculator-symbolic",
                                    GTK_ICON_SIZE_SMALL_TOOLBAR), "Oblicz równanie");
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), add_toolb, -1);

    //jakis wybor nr 2
    edit_toolb = gtk_tool_button_new(gtk_image_new_from_icon_name("input-tablet-symbolic",
                                     GTK_ICON_SIZE_SMALL_TOOLBAR), "Wyświetl wykres");
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), edit_toolb, -1);

    //separator1
    separator1 = gtk_separator_tool_item_new();
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), separator1, -1);
    
    //opcje
    options_toolb = gtk_tool_button_new(gtk_image_new_from_icon_name("system-run-symbolic",
                                        GTK_ICON_SIZE_SMALL_TOOLBAR), "Opcje");
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), options_toolb, -1);
    //info
    info_toolb = gtk_tool_button_new(gtk_image_new_from_icon_name("dialog-information-symbolic",
                                     GTK_ICON_SIZE_SMALL_TOOLBAR), "info");
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), info_toolb, -1);
    gtk_tool_item_set_tooltip_markup(info_toolb, "Info");
    //wyjście
    exit_toolb = gtk_tool_button_new(gtk_image_new_from_icon_name("application-exit-symbolic",
                                     GTK_ICON_SIZE_SMALL_TOOLBAR), "Wyjście");
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), exit_toolb, -1);



    gtk_box_pack_start(GTK_BOX(box), toolbar, FALSE, FALSE, 5);

    //lista
    sw = gtk_scrolled_window_new(NULL, NULL);
    gtk_scrolled_window_set_shadow_type(GTK_SCROLLED_WINDOW(sw), GTK_SHADOW_ETCHED_IN);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(sw), GTK_POLICY_NEVER, GTK_POLICY_AUTOMATIC);
    gtk_box_pack_start(GTK_BOX(box), sw, TRUE, TRUE, 0);


    gtk_widget_show_all(window);
    g_object_unref(icon);
    gtk_main();

    return 0;
}

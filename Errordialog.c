#include <gtk/gtk.h>
#include<stdio.h>

static void
print_error (GtkWidget *widget,
		gpointer   data)
{
	// Do Nothing
}

static void
activate (GtkApplication *app,
		gpointer user_data)
{
	GtkWidget *window;
	GtkWidget *button;
	GtkWidget *button_box;

	window = gtk_application_window_new (app);
	gtk_window_set_default_size (GTK_WINDOW (window), 200, 100);

	button_box = gtk_button_box_new (GTK_ORIENTATION_HORIZONTAL);
	gtk_container_add (GTK_CONTAINER (window), button_box);

	button = gtk_button_new_with_label ("This is test Error dialog----- \n!");
	g_signal_connect (button, "clicked", G_CALLBACK (print_error), NULL);
	g_signal_connect_swapped (button, "clicked", G_CALLBACK (gtk_widget_destroy), window);
	gtk_container_add (GTK_CONTAINER (button_box), button);
	gtk_widget_set_size_request(button, 200, 50 );

	gtk_widget_show_all (window);
}

int showErrorDialog ()
{
	GtkApplication *app;
	int status;

	app = gtk_application_new ("wwan.dpr.error", G_APPLICATION_FLAGS_NONE);
	g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
	status = g_application_run (G_APPLICATION (app), 0, 0);
	g_object_unref (app);

	return 1;
}


int main() {

	int ret = showErrorDialog();
	sleep(5);
	return 0;
}

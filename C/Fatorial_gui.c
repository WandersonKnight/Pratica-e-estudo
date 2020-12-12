#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <gtk/gtk.h>

static GtkWidget *number;
static GtkWidget *result;

// Usar gcc fatorial_gui.c -o Fatorial `pkg-config --cflags gtk+-3.0` `pkg-config --libs gtk+-3.0`

void fatorial(GtkWidget *fbutton, gpointer data){
	
    long long int num = atoi((char *)gtk_entry_get_text(GTK_ENTRY(number)));
	long long int i;
	char storage[64];
	long long int temp = 1;
	
	for(i = 1; i <= num; i++){
		
		temp = temp * i;
		
	}
	
	sprintf(storage, "A fatorial de %lld é: %lld", num, temp);
	
	gtk_label_set_text(GTK_LABEL(result), storage);
	
}

int main(int argc, char **argv){
	
	GtkWidget *window;
	GtkWidget *grid;
    GtkWidget *fbutton;
	
    gtk_init(&argc, &argv);
	
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
	
	grid = gtk_grid_new();
	gtk_container_add(GTK_CONTAINER(window), grid);
	
	number = gtk_entry_new();
	gtk_grid_attach(GTK_GRID(grid), number, 0, 0, 1, 1);
	
	fbutton = gtk_button_new_with_label("Calcular");
	g_signal_connect(fbutton, "clicked", G_CALLBACK(fatorial), NULL);
	gtk_grid_attach(GTK_GRID(grid), fbutton, 1, 0, 1, 1);
	
	result = gtk_label_new("Resultado");
	gtk_grid_attach(GTK_GRID(grid), result, 0, 1, 2, 1);
	
	gtk_widget_show_all(window);
	gtk_main();
	
	return 0;
	
}
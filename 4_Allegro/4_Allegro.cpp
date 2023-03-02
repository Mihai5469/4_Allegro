// 02/03/2023
// Iachimovschi Mihai
// Programma che fa rimbalzare le paline

#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <Windows.h>

using namespace std;

int main()
{
   
    int raggio = 30;        // il raggio della palina
    int x = 540, y = 240;   // coordinate
    int w = 1080, h = 800;  // dimensioni schermo
    
    int r = 10, g = 10, b = 10;     // valori usati per i colori

    bool rim = true;        // Variabile di sostegno
    bool rim2 = true;       // Variabile di sostegno
    
    // inizializazione delle librerie Allegro5 usate
    al_init();
    al_init_primitives_addon();
    al_init_image_addon();

    // Dachiarazione variabili Allegro5 
    ALLEGRO_DISPLAY* display = al_create_display(w, h);

    while (true) {

        // condizione che modifixa le coordinate x
        if (x < w - raggio && rim == true) {
            x++;
        }
        else
            rim = false;

        if (x > 0 + raggio &&  rim == false) {
            x--;  
        }
        else
            rim = true;
        // condizione che modifixa le coordinate y
        if (y < h - raggio && rim2 == true) {
            y++;
        }
        else
            rim2 = false;

        if (y > 0 + raggio && rim2 == false) {
            y--;   
        }
        else
            rim2 = true;

        // cambia il colore della palina al rimbalzo
        if (x == w - raggio || x == 0 + raggio || y == h - raggio || y == 0 + raggio) {
            r = rand() % 255 + 1;
            g = rand() % 255 + 1;
            b = rand() % 255 + 1;       
        }
              
        al_clear_to_color(al_map_rgb(255, 255, 255));                       // pulisce la finistra impostandala bianca
        al_draw_filled_circle(x, y, raggio, al_map_rgb(r, g, b));           // disegna la palina

        al_flip_display();          //crea la finesta con tutti gli elementi di sopra
        Sleep(1);                   // ferma il loop per 1 milisecondo

    }

    return 0;
}

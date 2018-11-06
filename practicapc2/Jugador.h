#pragma once
#include "String.h"
enum Direcciones { arriba, abajo, izquierda, derecha, ninguna };
using namespace System::Drawing;
using namespace System;
class Jugador
{
private:
	int x, y;
	int dx, dy;
	char*imagen;//nombre del archivo
	int ancho, alto;//tamaño de la imagen
	int indicex, indicey;//recorrido de la imagen (filas y columnas)
	Direcciones direccion;//va identificar que movimiento estamos dando
	Direcciones ultima;//se utiliza en el key_up y va a obtener la ultima tecla que presionamos
public:
	Jugador(void);
	~Jugador(void);
	void set_x(int nuevo);
	void set_y(int nuevo);
	int get_x();
	int get_y();
	int get_dx();
	int get_dy();
	int get_ancho();
	int get_alto();
	void cambiar_imagen(char*nuevo);
	void mostrar(Graphics^gr);
	void Mover(Graphics^gr);
	void setdireccion(Direcciones teclapulsada);
};
Jugador::Jugador(void)
{
	dx = 10;
	dy = 10;
	indicex = indicey = 0;
	imagen = new char[50];
	direccion = ninguna;
	ultima = izquierda;
}
Jugador::~Jugador(void)
{

}
void Jugador::set_y(int nuevo)
{
	y = nuevo;
}
void Jugador::set_x(int nuevo)
{
	x = nuevo;
}
int Jugador::get_x()
{
	return x;
}
int Jugador::get_y()
{
	return y;
}
int Jugador::get_dx()
{
	return dx;
}
int Jugador::get_dy()
{
	return dy;
}
int Jugador::get_ancho()
{
	return ancho;
}
int Jugador::get_alto()
{
	return alto;
}
void Jugador::cambiar_imagen(char*nuevo)
{
	strcpy(imagen, nuevo);
	Bitmap^bmp = gcnew Bitmap(gcnew String(imagen));
	ancho = (bmp->Width) / 12;//solo toma el ancho de un personaje
	alto = (bmp->Height) / 8;//solo toma el alto de un personaje
	delete bmp;
}
void Jugador::mostrar(Graphics^gr)
{
	x += dx;
	y += dy;
	Bitmap^bmp = gcnew Bitmap(gcnew String(imagen));
	System::Drawing::Rectangle porcion = System::Drawing::Rectangle(indicex*ancho, indicey*alto, ancho, alto);
	System::Drawing::Rectangle zoom = System::Drawing::Rectangle(x, y, ancho, alto);
	gr->DrawImage(bmp, zoom, porcion, GraphicsUnit::Pixel);
}
void Jugador::Mover(Graphics^gr)
{
	switch (direccion)
	{
	case arriba:
	{
		indicey = 3;
		
		if (indicex < 2)
		{
			indicex++;
		}
		else
		{
			indicex = 0;
		}
		dy = -5;
		dx = 0;
		ultima = arriba;
		break;
	}
	case abajo:
	{
		indicey = 0;
		if (indicex < 2)
		{
			indicex++;
		}
		else
		{
			indicex = 0;
		}
		dy = 5;
		dx = 0;
		ultima = abajo;
		break;
	}
	case izquierda:
	{
		indicey = 1;
		if (indicex < 2)
		{
			indicex++;
		}
		else
		{
			indicex = 0;
		}
		dy = 0;
		dx = -5;
		ultima = izquierda;

		break;
	}
	case derecha:
	{
		indicey = 2;
		if (indicex < 2)
		{
			indicex++;
		}
		else
		{
			indicex = 0;
		}
		dy = 0;
		dx = 5;
		ultima = derecha;
		break;
	}
	case ninguna:
	{
		dx = 0;
		dy = 0;
		if (ultima==abajo)
		{
			indicex = 0;
			indicey = 0;
		}
		if (ultima == izquierda)
		{
			indicex = 0;
			indicey = 1;
		}
		if (ultima == derecha)
		{
			indicex = 0;
			indicey = 2;
		}
		if (ultima == arriba)
		{
			indicex = 0;
			indicey = 3;
		}
		break;
	}
	default:
		break;
	}
	mostrar(gr);
}
void Jugador::setdireccion(Direcciones teclapulsada)
{
	direccion = teclapulsada;
}
#pragma once
#include "Jugador.h"
namespace practicapc2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			objJugador = new Jugador();
			objJugador->set_x(100);
			objJugador->set_y(100);
			objJugador->cambiar_imagen("waifu.png");

			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		Jugador *objJugador;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::ComponentModel::IContainer^  components;
			 /// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(595, 423);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyUp);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) 
	{
		Graphics^gr = this->CreateGraphics();
		System::Drawing::BufferedGraphicsContext ^bc = BufferedGraphicsManager::Current;
		System::Drawing::BufferedGraphics ^bg = bc->Allocate(gr, this->ClientRectangle);
		bg->Graphics->Clear(Color::White);
		objJugador->Mover(bg->Graphics);

		bg->Render(gr);
		delete gr;
		delete bc;
		delete bg;
	}






	private: System::Void MyForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) 
	{
		switch (e->KeyCode)
		{
		case Keys::Up:
			objJugador->setdireccion(arriba);
			break;

		case Keys::Left://Izquierda
			objJugador->setdireccion(izquierda);
			break;
		case Keys::Right://derecha
			objJugador->setdireccion(derecha);
			break;

		case Keys::Down://abajo
			objJugador->setdireccion(abajo);
			break;
		default:
			break;
		}


	}
	private: System::Void MyForm_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) 
	{
		switch (e->KeyCode)
		{
		default:
			objJugador->setdireccion(ninguna);
			break;
		}
	
	
	}
};
}

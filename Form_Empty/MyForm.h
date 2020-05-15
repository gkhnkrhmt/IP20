#pragma once
#include <Windows.h>
#include <atlstr.h>
#include "imge_bmp.h"
#include <iostream>
#include <fstream>
namespace Form_Empty {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		LPCTSTR input, output;
		int Width, Height;
		int* thresharray;
		char* clusteredpiksels;
		long Size, new_size;
		BYTE* buffer;
		BYTE* raw_intensity;
		BYTE* raw_intensity2;
		int** bounding_val;
		int** label_num;
		int labelNo = 0;
		double** fi;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	private: System::Windows::Forms::ToolStripMenuItem^ fillChartToolStripMenuItem;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::ToolStripMenuItem^ clusteredImageToolStripMenuItem;
	private: System::Windows::Forms::PictureBox^ pictureBox4;
	private: System::Windows::Forms::ToolStripMenuItem^ meanFilterToolStripMenuItem;
	private: System::Windows::Forms::PictureBox^ pictureBox5;
	private: System::Windows::Forms::ToolStripMenuItem^ morphologyToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ erosionToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ dilationToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ openingToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ closingToolStripMenuItem;
	private: System::Windows::Forms::PictureBox^ pictureBox6;

	private: System::Windows::Forms::ToolStripMenuItem^ showÝntenseToolStripMenuItem;
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ openToolStripMenuItem;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->showÝntenseToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->fillChartToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->clusteredImageToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->meanFilterToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->morphologyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->erosionToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->dilationToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openingToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->closingToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox6 = (gcnew System::Windows::Forms::PictureBox());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->fileToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1483, 28);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->openToolStripMenuItem,
					this->showÝntenseToolStripMenuItem, this->fillChartToolStripMenuItem, this->clusteredImageToolStripMenuItem, this->meanFilterToolStripMenuItem,
					this->morphologyToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(46, 24);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->Size = System::Drawing::Size(200, 26);
			this->openToolStripMenuItem->Text = L"Open";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::openToolStripMenuItem_Click);
			// 
			// showÝntenseToolStripMenuItem
			// 
			this->showÝntenseToolStripMenuItem->Name = L"showÝntenseToolStripMenuItem";
			this->showÝntenseToolStripMenuItem->Size = System::Drawing::Size(200, 26);
			this->showÝntenseToolStripMenuItem->Text = L"Show Intense";
			this->showÝntenseToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::showÝntenseToolStripMenuItem_Click);
			// 
			// fillChartToolStripMenuItem
			// 
			this->fillChartToolStripMenuItem->Name = L"fillChartToolStripMenuItem";
			this->fillChartToolStripMenuItem->Size = System::Drawing::Size(200, 26);
			this->fillChartToolStripMenuItem->Text = L"Fill Chart";
			this->fillChartToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::fillChartToolStripMenuItem_Click);
			// 
			// clusteredImageToolStripMenuItem
			// 
			this->clusteredImageToolStripMenuItem->Name = L"clusteredImageToolStripMenuItem";
			this->clusteredImageToolStripMenuItem->Size = System::Drawing::Size(200, 26);
			this->clusteredImageToolStripMenuItem->Text = L"Clustered Image";
			this->clusteredImageToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::clusteredImageToolStripMenuItem_Click);
			// 
			// meanFilterToolStripMenuItem
			// 
			this->meanFilterToolStripMenuItem->Name = L"meanFilterToolStripMenuItem";
			this->meanFilterToolStripMenuItem->Size = System::Drawing::Size(200, 26);
			this->meanFilterToolStripMenuItem->Text = L"Mean Filter";
			this->meanFilterToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::meanFilterToolStripMenuItem_Click);
			// 
			// morphologyToolStripMenuItem
			// 
			this->morphologyToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->erosionToolStripMenuItem,
					this->dilationToolStripMenuItem, this->openingToolStripMenuItem, this->closingToolStripMenuItem
			});
			this->morphologyToolStripMenuItem->Name = L"morphologyToolStripMenuItem";
			this->morphologyToolStripMenuItem->Size = System::Drawing::Size(200, 26);
			this->morphologyToolStripMenuItem->Text = L"Morphology";
			// 
			// erosionToolStripMenuItem
			// 
			this->erosionToolStripMenuItem->Name = L"erosionToolStripMenuItem";
			this->erosionToolStripMenuItem->Size = System::Drawing::Size(149, 26);
			this->erosionToolStripMenuItem->Text = L"Erosion";
			this->erosionToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::erosionToolStripMenuItem_Click);
			// 
			// dilationToolStripMenuItem
			// 
			this->dilationToolStripMenuItem->Name = L"dilationToolStripMenuItem";
			this->dilationToolStripMenuItem->Size = System::Drawing::Size(149, 26);
			this->dilationToolStripMenuItem->Text = L"Dilation";
			this->dilationToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::dilationToolStripMenuItem_Click);
			// 
			// openingToolStripMenuItem
			// 
			this->openingToolStripMenuItem->Name = L"openingToolStripMenuItem";
			this->openingToolStripMenuItem->Size = System::Drawing::Size(149, 26);
			this->openingToolStripMenuItem->Text = L"Opening";
			// 
			// closingToolStripMenuItem
			// 
			this->closingToolStripMenuItem->Name = L"closingToolStripMenuItem";
			this->closingToolStripMenuItem->Size = System::Drawing::Size(149, 26);
			this->closingToolStripMenuItem->Text = L"Closing";
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(13, 32);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(4);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(346, 258);
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &MyForm::pictureBox1_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->Location = System::Drawing::Point(402, 32);
			this->pictureBox2->Margin = System::Windows::Forms::Padding(4);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(293, 258);
			this->pictureBox2->TabIndex = 2;
			this->pictureBox2->TabStop = false;
			// 
			// chart1
			// 
			chartArea1->AxisX->Interval = 5;
			chartArea1->AxisX2->Interval = 1;
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(703, 17);
			this->chart1->Margin = System::Windows::Forms::Padding(4);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->Legend = L"Legend1";
			series1->Name = L"chart";
			series1->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::UInt32;
			series1->YValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::UInt32;
			this->chart1->Series->Add(series1);
			this->chart1->Size = System::Drawing::Size(621, 379);
			this->chart1->TabIndex = 3;
			this->chart1->Text = L"chart1";
			// 
			// pictureBox3
			// 
			this->pictureBox3->Location = System::Drawing::Point(51, 86);
			this->pictureBox3->Margin = System::Windows::Forms::Padding(4);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(508, 325);
			this->pictureBox3->TabIndex = 4;
			this->pictureBox3->TabStop = false;
			this->pictureBox3->Click += gcnew System::EventHandler(this, &MyForm::pictureBox3_Click);
			// 
			// pictureBox4
			// 
			this->pictureBox4->Location = System::Drawing::Point(93, 139);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(466, 304);
			this->pictureBox4->TabIndex = 5;
			this->pictureBox4->TabStop = false;
			this->pictureBox4->Click += gcnew System::EventHandler(this, &MyForm::pictureBox4_Click);
			// 
			// pictureBox5
			// 
			this->pictureBox5->Location = System::Drawing::Point(753, 139);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(444, 342);
			this->pictureBox5->TabIndex = 6;
			this->pictureBox5->TabStop = false;
			this->pictureBox5->Click += gcnew System::EventHandler(this, &MyForm::pictureBox5_Click);
			// 
			// pictureBox6
			// 
			this->pictureBox6->Location = System::Drawing::Point(302, 197);
			this->pictureBox6->Name = L"pictureBox6";
			this->pictureBox6->Size = System::Drawing::Size(414, 284);
			this->pictureBox6->TabIndex = 7;
			this->pictureBox6->TabStop = false;
			this->pictureBox6->Click += gcnew System::EventHandler(this, &MyForm::pictureBox6_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1483, 556);
			this->Controls->Add(this->pictureBox6);
			this->Controls->Add(this->pictureBox5);
			this->Controls->Add(this->pictureBox4);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void openToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		CString str;
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			str = openFileDialog1->FileName;
			input = (LPCTSTR)str;
			//BMP image reading
			buffer = LoadBMP(Width, Height, Size, input);
			pictureBox1->Width = Width;
			pictureBox1->Height = Height;
			pictureBox1->ImageLocation = openFileDialog1->FileName;
		}
	}
	private: System::Void showÝntenseToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	    raw_intensity = ConvertBMPToIntensity(buffer, Width, Height);
		raw_intensity2 = ConvertBMPToIntensity(buffer, Width, Height);
		pictureBox2->Width = Width;
		pictureBox2->Height = Height;
		Bitmap^ surface = gcnew Bitmap(pictureBox2->Width, pictureBox2->Height );
		pictureBox2->Image = surface;
		Color c;
		for(int row = 0; row < Height; row++)
		{
			for (int col = 0; col < Width; col++)
			{
				c = Color::FromArgb(*(raw_intensity + row * Width+col),*(raw_intensity + row * Width + col), *(raw_intensity + row * Width + col));
				surface->SetPixel(col, row, c);
			}
		}
		
	}
    private: System::Void fillChartToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		
		int toplam = 0;
		thresharray = new int[256];
		for (int row = 0; row <= 255; row++)
		{
			for (int col = 0; col < Width*Height; col++)
			{
				if ( raw_intensity[col] == row)
				{
					toplam++;	
					
				}
			}

			chart1->Series["chart"]->Points->AddXY(row+1, toplam);
			thresharray[row] = toplam;
			toplam = 0;
			
		}//endfor
			//threshold kýsmý!!!!!!!!!!!!!!!

		pictureBox3->Width = Width;
		pictureBox3->Height = Height;
		Bitmap^ surface = gcnew Bitmap(pictureBox3->Width, pictureBox3->Height);
		pictureBox3->Image = surface;
		Color c;
		
		for (int row = 0; row < Height; row++)
		{
			for (int col = 0; col < Width; col++)
			{
				c = Color::FromArgb(*(raw_intensity + row * Width + col), *(raw_intensity + row * Width + col), *(raw_intensity + row * Width + col));
				surface->SetPixel(col, row, c);
			}
		}

    }
 private: System::Void clusteredImageToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	 int threshold1 = 0;
	 int threshold2 = 0;
	 int center1 = 150;
	 int center1points = 0;//counts center1's points
	 int center2 = 180;
	 int center2points = 0;//counts center2's points
	 clusteredpiksels = new char[256];
	 while (center1 != threshold1 || center2 != threshold2) {
		 threshold1 = center1;
		 threshold2 = center2;
		 for (int i = 0; i < 255; i++) {
			 if (abs(threshold1 - i) < abs(threshold2 - i)) {
				 clusteredpiksels[i] = 'a'; //if piksel near to threshold1
			 }
			 else
			 {
				 clusteredpiksels[i] = 'b';
			 }
		 }//Pikseller clustered'landý.
		 center1 = 0;
		 center2 = 0;
		 for (int i = 0; i < 255; i++) {
			 if (clusteredpiksels[i] == 'a') {
				 center1 += i * thresharray[i];
				 center1points += thresharray[i];
			 }
			 else
			 {
				 center2 += i * thresharray[i];
				 center2points += thresharray[i];
			 }
		 }
		 center1 = center1 / center1points;
		 center2 = center2 / center2points;
		 center1points = 0;
		 center2points = 0;
	 }
	 for (int col = 0; col < Width* Height; col++)
	{
		if (abs(center1 - raw_intensity[col]) < abs(center2 - raw_intensity[col]))
		{
			raw_intensity[col] = 0; //center1'a yakýnsa 255 yap.
		}
		else {
			raw_intensity[col] = 1;
		}
	}
	 pictureBox4->Width = Width;
	 pictureBox4->Height = Height;
	 Bitmap^ surface = gcnew Bitmap(pictureBox4->Width, pictureBox4->Height);
	 pictureBox4->Image = surface;
	 Color c;
	 for (int row = 0; row < Height; row++)
	 {
		 for (int col = 0; col < Width; col++)
		 {
			 c = Color::FromArgb(*(raw_intensity + row * Width + col), *(raw_intensity + row * Width + col), *(raw_intensity + row * Width + col));
			 surface->SetPixel(col, row, c);
		 }
	 }
 }
private: System::Void pictureBox4_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void meanFilterToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		int index = 0,ct=0;
		unsigned char hold=0;
		unsigned char*  median= new char unsigned[9];
		for (int k = 0; k < (Width-2) * (Height-2); k++) {
			for (int j = 0; j < 3; j++) {
				for (int i = 0; i < 3; i++) {
					median[ct] = raw_intensity[index + i + k];
					ct++;
				}
				index += Width;
			}
			ct = 0;
			index = 0;
			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 9; j++)
				{
					if (median[j] > median[j + 1]) {
						hold = median[j + 1];
						median[j + 1] = median[j];
						median[j] = hold;
					}
				}
			}
			raw_intensity[k] = median[4];
		}
	
	
	pictureBox5->Width = Width;//he
	pictureBox5->Height = Height;
	Bitmap^ surface = gcnew Bitmap(pictureBox5->Width, pictureBox5->Height);
	pictureBox5->Image = surface;
	Color c;
	for (int row = 0; row < Height; row++)
	{
		for (int col = 0; col < Width; col++)
		{
			c = Color::FromArgb(*(raw_intensity + row * Width + col), *(raw_intensity + row * Width + col), *(raw_intensity + row * Width + col));
			surface->SetPixel(col, row, c);
		}
	}
}
private: System::Void pictureBox5_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void pictureBox3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void erosionToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	Erosion();
	pictureBox6->Width = Width;
	pictureBox6->Height = Height;
	Bitmap^ surface = gcnew Bitmap(pictureBox6->Width, pictureBox6->Height);
	pictureBox6->Image = surface;
	Color c;
	for (int row = 0; row < Height; row++)
	{
		for (int col = 0; col < Width; col++)
		{
			c = Color::FromArgb(*(raw_intensity2 + row * Width + col), *(raw_intensity2 + row * Width + col), *(raw_intensity2 + row * Width + col));
			surface->SetPixel(col, row, c);
		}
	}
	for (int row = 0; row < Width * Height; row++)
	{
		raw_intensity[row] = raw_intensity2[row];//raw_intensity elemanlarýný raw_intensity dizisine aktarma
	}
}
private: System::Void dilationToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	Dilation();
	pictureBox6->Width = Width;
	pictureBox6->Height = Height;
	Bitmap^ surface = gcnew Bitmap(pictureBox6->Width, pictureBox6->Height);
	pictureBox6->Image = surface;
	Color c;
	for (int row = 0; row < Height; row++)
	{
		for (int col = 0; col < Width; col++)
		{
			c = Color::FromArgb(*(raw_intensity2 + row * Width + col), *(raw_intensity2 + row * Width + col), *(raw_intensity2 + row * Width + col));
			surface->SetPixel(col, row, c);
		}
	}
	for (int row = 0; row < Width * Height; row++)
	{
		raw_intensity[row] = raw_intensity2[row];//raw_intensity elemanlarýný raw_intensity dizisine aktarma
	}
}
public: void Erosion() {
	bool binary_val = 1;
	for (int row = 0; row < Width; row++)
	{
		for (int col = 0; col < Height ; col++) {
			if (col == Height - 1 || col == 0 || row == 0 || row == Width - 1) {//resmin dýþ kýsmýný 0 yapma
				raw_intensity2[row + (col * Width)] = 0;
			}
		}
	}
	for (int row = 0; row < Width-1; row++)
	{
		for (int col = 0; col < Height-1; col++)
		{
			
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					binary_val &= raw_intensity[(row + i) + (col + j) * Width];
				}
			}
			if (!binary_val) {
				raw_intensity2[(row + 1) + (col + 1) * Width] = 0;
			}
			binary_val = 1;
		}
	}

}
public: void Dilation(){
	bool binary_val = 0;
		for (int row = 0; row < Width; row++)
	{
		for (int col = 0; col < Height ; col++) {
			if (col == Height - 1 || col == 0 || row == 0 || row == Width - 1) {//resmin dýþ kýsmýný 0 yapma
				raw_intensity2[row + (col * Width)] = 0;
			}
		}
	}
	for (int row = 0; row < Width - 1; row++)
	{
		for (int col = 0; col < Height - 1; col++)
		{
			binary_val = 0;
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					binary_val |= raw_intensity[(row + i) + (col + j) * Width];
				}
			}
			if (binary_val) {
				raw_intensity2[(row + 1) + (col + 1) * Width] = 255;
			}
		}
	}

}
public: void Opening() {
	Erosion();
	Dilation();
}
public: void Closing() {
	Dilation();
	Erosion();
}

private: System::Void pictureBox6_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
}
public: void Labeling() {
	int KomsularinEnKucukEtiketDegeri;
	
	for (int i = 0; i < Height; i++)
	{
		label_num = new int* [Width];
	}
	for (int i = 0; i < Width; i++)
	{
		for (int j = 0; j < Height; j++)
		{
			label_num[i][j] = 0;
		}
	}
	int ilkdeger = 0, sondeger = 0;
	bool degisim = true;
	while (degisim == true)
	{
		degisim = false;
		for (int i = 1; i < Width; i++)
		{
			for (int j = 1; j < Height; j++)
			{
				if (raw_intensity[i * Width + j] != 0)
				{
					ilkdeger = label_num[i][j];

					KomsularinEnKucukEtiketDegeri = 0;
					for (int k = -1; k <= 1; k++)
					{
						for (int l = -1; l <= 1; l++)
						{
							if (label_num[i + k][j + l] != 0 && KomsularinEnKucukEtiketDegeri == 0)
							{
								KomsularinEnKucukEtiketDegeri = label_num[i + k][j + l];
							}
							else if (label_num[i + k][j + l] < KomsularinEnKucukEtiketDegeri && label_num[i + k][j + l] != 0 && KomsularinEnKucukEtiketDegeri != 0)
							{
								KomsularinEnKucukEtiketDegeri = label_num[i + k][j + l];
							}
						}
					}
					if (KomsularinEnKucukEtiketDegeri != 0)
					{
						label_num[i][j] = KomsularinEnKucukEtiketDegeri;
					}
					else if (KomsularinEnKucukEtiketDegeri == 0)
					{
						labelNo++;
						label_num[i][j] = labelNo;
					}
					sondeger = label_num[i][j];
					if (ilkdeger != sondeger)
						degisim = TRUE;
				}

			}
		}
	} 

}
public: void creatBoundingBox() {
	int enkucukX, enkucukY, enbuyukX, enbuyukY;//bounding box için ayrý bir byte dizisi kullan. raw_intensity kullanma.
	for (int i = 0; i < labelNo; i++)
	{
		bounding_val = new int* [2];
	}
	for (int k = 1; k <= labelNo; k++)
	{
		enkucukX = Width;
		enkucukY = Height;
		enbuyukX, enbuyukY = 0;
		for (int i = 0; i < Width; i++)
		{
			for (int j = 0; j < Height; j++)
			{
				if (label_num[i][j] == k) {
					if (i < enkucukX)enkucukX = i;
					if (j < enkucukY)enkucukY = j;
					if (i > enbuyukX)enbuyukX = i;
					if (j > enbuyukY)enbuyukY = j;
				}
			}
		}
		bounding_val[k-1][0] = enbuyukX - enkucukX;//c
		//Moment için r ve c deðerleri bulundu bounding box'ýn.
		bounding_val[k-1][1] = enbuyukY - enkucukY;//r
		for (int i = 0; i < Height; i++)
		{
			for (int j = 0; j < Width; j++)
			{
				if (j == enbuyukY || j == enkucukY || i == enkucukX || i == enbuyukX) {//resmin dýþ kýsmýný 0 yapma
					raw_intensity2[i + (j * Width)] = 128;
				}
			}
		}
	}

}
public: void Moments() {
	
	double** moments;
	double** centers;
	double M20, M02, M11, M30, M12, M21, M03, M21;
	
	for (int i = 0; i < labelNo; i++)
	{
		moments = new double*[4];
	}
	for (int i = 0; i < labelNo; i++)
	{
		centers = new double* [2];
	}
	for (int i = 0; i < labelNo; i++)
	{
		fi = new double* [7];
	}
		for (int k = 1; k < labelNo; k++)
		{
			for (int raw = 0; raw < Width; raw++)
			{
				for (int col = 0; col < Height; col++)
				{
					if (label_num[raw][col]==k)
					{
						for (int i = 0; i < bounding_val[k][0]; i++)
						{
							for (int j = 0; j < bounding_val[k][1]; j++)
							{
								//4 tane deðeer hesaplicaz M00 M01 M11 M10    -> 
								moments[k - 1][0] = i ^ 0 * j ^ 0 * raw_intensity[(raw + i) * Width + col + j];
								moments[k - 1][1] = i ^ 0 * j ^ 1 * raw_intensity[(raw + i) * Width + col + j];
								moments[k - 1][2] = i ^ 1 * j ^ 1 * raw_intensity[(raw + i) * Width + col + j];
								moments[k - 1][3] = i ^ 1 * j ^ 0 * raw_intensity[(raw + i) * Width + col + j];
								centers[k][0] = moments[k - 1][3] / moments[k - 1][0];//r üssü için center deðeri
								centers[k][1] = moments[k - 1][1] / moments[k - 1][0];//c üssü için center deðeri
								//7 tane fi deðeri bulucaz bunlar için M20 M02 M11 M30 M12 M21 M03 M21
								M20 = pow((i - centers[k][0]), 2) * pow((j - centers[k][1]), 0) * raw_intensity[(raw + i) * Width + col + j];
								M02 = pow((i - centers[k][0]), 0) * pow((j - centers[k][1]), 2) * raw_intensity[(raw + i) * Width + col + j];
								M11 = pow((i - centers[k][0]), 1) * pow((j - centers[k][1]), 1) * raw_intensity[(raw + i) * Width + col + j];
								M30 = pow((i - centers[k][0]), 3) * pow((j - centers[k][1]), 0) * raw_intensity[(raw + i) * Width + col + j];
								M12 = pow((i - centers[k][0]), 1) * pow((j - centers[k][1]), 2) * raw_intensity[(raw + i) * Width + col + j];
								M20 = pow((i - centers[k][0]), 2) * pow((j - centers[k][1]), 0) * raw_intensity[(raw + i) * Width + col + j];
								M21 = pow((i - centers[k][0]), 2) * pow((j - centers[k][1]), 1) * raw_intensity[(raw + i) * Width + col + j];
								M03 = pow((i - centers[k][0]), 0) * pow((j - centers[k][1]), 3) * raw_intensity[(raw + i) * Width + col + j];
								M21 = pow((i - centers[k][0]), 2) * pow((j - centers[k][1]), 1) * raw_intensity[(raw + i) * Width + col + j];
								fi[k - 1][0] = M20 + M02;
								fi[k - 1][1] = pow((M20 - M02),2)+4*pow(M11,2);
								fi[k - 1][2] = pow((M30 - 3*M12),2)+pow((3*M21-M03),2);
								fi[k - 1][3] = pow((M30 + M12), 2) + pow((M21 + M03), 2);
								fi[k - 1][4] = (M30 - 3 * M12) * (M30 + M12) * ((pow((M30 + M12), 2) - 3 * pow((M21 + M03), 2) )) + (3 * M12 - M03) * (M21 + M03) * (3 * pow((M30 + M12), 2) - (pow((M21 + M03), 2)));
								fi[k - 1][5] = (M20 - M02) * (pow(M30 + M12, 2) - pow(M21 + M03, 2)) + 4 * M11 * (M30 + M12) * (M21 + M03);
								fi[k - 1][6] = (3 * M21 - M03) * (M30 + M12) * (pow(M30 + M12, 2) - 3 * pow(M21 + M03, 2)) + 3 * (M21 - M03) * (M21 + M03) * (3 * pow(M30 + M12, 2) - pow(M21 + M03, 2));
							}
						}
						raw = raw + bounding_val[k][0];
						col = col + bounding_val[k][1];
					}
				}
			}
		}

}
public: void training()	{
	std::ofstream dosya; 
	dosya.open("training.txt");
	for (int i = 0; i < labelNo; i++)
	{	
		for (int j = 0; j < 7; j++)
		{
			dosya << fi[i][j] << " ";
		}
		dosya << std::endl;
	}
	dosya << "Dosyaya yazi yazdim."; 
	dosya.close();
}
public: void testing() {
	std::ifstream dosya;
	dosya.open("training.txt");
	double hold;
	double sum=0;
	double distance=0;
	double hdistance = 10000000;
	int index;
	int* countoflabel;
	
	for (int i = 0; i < labelNo; i++)
	{
		while (!EOF) {
		distance = 0;
		sum = 0;
		for (int j = 0; j < 7; j++)
		{
			 dosya >> hold;
			 sum = fi[i][j] - hold;
			 sum = sum * sum;
			 distance += sum;
		}
		if (hdistance>distance)
		{
			hdistance = distance;
			index = i;
		}
		}
		countoflabel[index]++;
	}
	
	
}
};
}
// 1 1 1 0
// 1 1 1 0
// 0 0 0 0
// 2 2 2 2
// 2 2 2 2
// 0 0 0 0
// 3 3 3 3
// 3 3 3 3


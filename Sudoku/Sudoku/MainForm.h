#pragma once
#include <vector>
#include <algorithm>
#include <numeric>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "chromosome.h"
#include <algorithm>
#include <random>
#include "Calculations.h"
#include <iostream> 
#include <string> 
#include <ctime>

namespace Sudoku
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;



	public ref class MainForm : public System::Windows::Forms::Form
	{
	private:
		/*static int randomPickByWeight(std::vector<Chromosome> chromosomes);
		static Chromosome mutate(Chromosome c, std::vector<std::vector<int>> initFilledPlaces);
		static Chromosome crossoverRows(Chromosome c1, Chromosome c2);
		static Chromosome crossoverCols(Chromosome c1, Chromosome c2);
		static Chromosome generateRandomChromosome(std::vector<std::vector<int>> sudokuMatrix);
		static	std::vector<Chromosome> generateRandomPool(std::vector<std::vector<int>> sudokuMatrix, int size);
		static double calcFitness(std::vector<std::vector<int>> sudokuMatrix);*/


	public:
		MainForm(void)
		{
			InitializeComponent();
		}

	protected:
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::RichTextBox^ richTextBox00;
	private: System::Windows::Forms::RichTextBox^ richTextBox01;
	private: System::Windows::Forms::RichTextBox^ richTextBox02;
	private: System::Windows::Forms::RichTextBox^ richTextBox03;
	private: System::Windows::Forms::RichTextBox^ richTextBox04;
	private: System::Windows::Forms::RichTextBox^ richTextBox05;
	private: System::Windows::Forms::RichTextBox^ richTextBox10;
	private: System::Windows::Forms::RichTextBox^ richTextBox11;
	private: System::Windows::Forms::RichTextBox^ richTextBox12;
	private: System::Windows::Forms::RichTextBox^ richTextBox13;
	private: System::Windows::Forms::RichTextBox^ richTextBox14;
	private: System::Windows::Forms::RichTextBox^ richTextBox15;
	private: System::Windows::Forms::RichTextBox^ richTextBox20;
	private: System::Windows::Forms::RichTextBox^ richTextBox21;
	private: System::Windows::Forms::RichTextBox^ richTextBox22;
	private: System::Windows::Forms::RichTextBox^ richTextBox23;
	private: System::Windows::Forms::RichTextBox^ richTextBox24;
	private: System::Windows::Forms::RichTextBox^ richTextBox25;
	private: System::Windows::Forms::RichTextBox^ richTextBox30;
	private: System::Windows::Forms::RichTextBox^ richTextBox31;
	private: System::Windows::Forms::RichTextBox^ richTextBox32;
	private: System::Windows::Forms::RichTextBox^ richTextBox33;
	private: System::Windows::Forms::RichTextBox^ richTextBox34;
	private: System::Windows::Forms::RichTextBox^ richTextBox35;
	private: System::Windows::Forms::RichTextBox^ richTextBox40;
	private: System::Windows::Forms::RichTextBox^ richTextBox41;
	private: System::Windows::Forms::RichTextBox^ richTextBox42;
	private: System::Windows::Forms::RichTextBox^ richTextBox43;
	private: System::Windows::Forms::RichTextBox^ richTextBox44;
	private: System::Windows::Forms::RichTextBox^ richTextBox45;
	private: System::Windows::Forms::RichTextBox^ richTextBox50;
	private: System::Windows::Forms::RichTextBox^ richTextBox51;
	private: System::Windows::Forms::RichTextBox^ richTextBox52;
	private: System::Windows::Forms::RichTextBox^ richTextBox53;
	private: System::Windows::Forms::RichTextBox^ richTextBox54;
	private: System::Windows::Forms::RichTextBox^ richTextBox55;
	private: System::Windows::Forms::Button^ solveButton;

	private: System::Windows::Forms::Button^ resetButton;
	private: System::Windows::Forms::Label^ label1;
	private: array <RichTextBox^, 2> ^ textBoxMatrix = gcnew array<RichTextBox^, 2>(6, 6);
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::ComboBox^ poolSizeComboBox;
	private: System::Windows::Forms::ComboBox^ mutationPercentageComboBox;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;


	private: System::ComponentModel::IContainer^ components;


	private: System::Windows::Forms::Button^ easyExampleButton;
	public:
	private: System::Windows::Forms::Button^ StandardExampleButton;
	private: System::Windows::Forms::Button^ hardExampleButton;
	private: int example;
	private: int isAnswer = 0;
	private: int ticks;
	private: int poolSize;
	private: int mutationPercent;
	private: System::Windows::Forms::CheckBox^ cheatBox;
	private: int ageLimit = 10;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->richTextBox00 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox01 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox02 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox03 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox04 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox05 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox10 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox11 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox12 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox13 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox14 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox15 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox20 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox21 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox22 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox23 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox24 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox25 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox30 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox31 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox32 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox33 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox34 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox35 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox40 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox41 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox42 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox43 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox44 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox45 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox50 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox51 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox52 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox53 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox54 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox55 = (gcnew System::Windows::Forms::RichTextBox());
			this->solveButton = (gcnew System::Windows::Forms::Button());
			this->resetButton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->poolSizeComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->mutationPercentageComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->easyExampleButton = (gcnew System::Windows::Forms::Button());
			this->StandardExampleButton = (gcnew System::Windows::Forms::Button());
			this->hardExampleButton = (gcnew System::Windows::Forms::Button());
			this->cheatBox = (gcnew System::Windows::Forms::CheckBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// richTextBox00
			// 
			this->richTextBox00->BackColor = System::Drawing::Color::White;
			this->richTextBox00->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 40));
			this->richTextBox00->Location = System::Drawing::Point(29, 30);
			this->richTextBox00->MaxLength = 1;
			this->richTextBox00->Name = L"richTextBox00";
			this->richTextBox00->Size = System::Drawing::Size(76, 76);
			this->richTextBox00->TabIndex = 0;
			this->richTextBox00->Text = L"";
			// 
			// richTextBox01
			// 
			this->richTextBox01->BackColor = System::Drawing::Color::White;
			this->richTextBox01->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 40));
			this->richTextBox01->Location = System::Drawing::Point(109, 30);
			this->richTextBox01->MaxLength = 1;
			this->richTextBox01->Name = L"richTextBox01";
			this->richTextBox01->Size = System::Drawing::Size(76, 76);
			this->richTextBox01->TabIndex = 1;
			this->richTextBox01->Text = L"";
			// 
			// richTextBox02
			// 
			this->richTextBox02->BackColor = System::Drawing::Color::White;
			this->richTextBox02->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 40));
			this->richTextBox02->Location = System::Drawing::Point(187, 30);
			this->richTextBox02->MaxLength = 1;
			this->richTextBox02->Name = L"richTextBox02";
			this->richTextBox02->Size = System::Drawing::Size(76, 76);
			this->richTextBox02->TabIndex = 2;
			this->richTextBox02->Text = L"";
			// 
			// richTextBox03
			// 
			this->richTextBox03->BackColor = System::Drawing::Color::White;
			this->richTextBox03->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 40));
			this->richTextBox03->Location = System::Drawing::Point(268, 30);
			this->richTextBox03->MaxLength = 1;
			this->richTextBox03->Name = L"richTextBox03";
			this->richTextBox03->Size = System::Drawing::Size(76, 76);
			this->richTextBox03->TabIndex = 3;
			this->richTextBox03->Text = L"";
			// 
			// richTextBox04
			// 
			this->richTextBox04->BackColor = System::Drawing::Color::White;
			this->richTextBox04->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 40));
			this->richTextBox04->Location = System::Drawing::Point(349, 30);
			this->richTextBox04->MaxLength = 1;
			this->richTextBox04->Name = L"richTextBox04";
			this->richTextBox04->Size = System::Drawing::Size(76, 76);
			this->richTextBox04->TabIndex = 4;
			this->richTextBox04->Text = L"";
			// 
			// richTextBox05
			// 
			this->richTextBox05->BackColor = System::Drawing::Color::White;
			this->richTextBox05->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 40));
			this->richTextBox05->Location = System::Drawing::Point(425, 30);
			this->richTextBox05->MaxLength = 1;
			this->richTextBox05->Name = L"richTextBox05";
			this->richTextBox05->Size = System::Drawing::Size(76, 76);
			this->richTextBox05->TabIndex = 5;
			this->richTextBox05->Text = L"";
			// 
			// richTextBox10
			// 
			this->richTextBox10->BackColor = System::Drawing::Color::White;
			this->richTextBox10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 40));
			this->richTextBox10->Location = System::Drawing::Point(30, 109);
			this->richTextBox10->MaxLength = 1;
			this->richTextBox10->Name = L"richTextBox10";
			this->richTextBox10->Size = System::Drawing::Size(76, 76);
			this->richTextBox10->TabIndex = 6;
			this->richTextBox10->Text = L"";
			// 
			// richTextBox11
			// 
			this->richTextBox11->BackColor = System::Drawing::Color::White;
			this->richTextBox11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 40));
			this->richTextBox11->Location = System::Drawing::Point(109, 108);
			this->richTextBox11->MaxLength = 1;
			this->richTextBox11->Name = L"richTextBox11";
			this->richTextBox11->Size = System::Drawing::Size(76, 76);
			this->richTextBox11->TabIndex = 7;
			this->richTextBox11->Text = L"";
			// 
			// richTextBox12
			// 
			this->richTextBox12->BackColor = System::Drawing::Color::White;
			this->richTextBox12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 40));
			this->richTextBox12->Location = System::Drawing::Point(187, 109);
			this->richTextBox12->MaxLength = 1;
			this->richTextBox12->Name = L"richTextBox12";
			this->richTextBox12->Size = System::Drawing::Size(76, 76);
			this->richTextBox12->TabIndex = 8;
			this->richTextBox12->Text = L"";
			// 
			// richTextBox13
			// 
			this->richTextBox13->BackColor = System::Drawing::Color::White;
			this->richTextBox13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 40));
			this->richTextBox13->Location = System::Drawing::Point(268, 109);
			this->richTextBox13->MaxLength = 1;
			this->richTextBox13->Name = L"richTextBox13";
			this->richTextBox13->Size = System::Drawing::Size(76, 76);
			this->richTextBox13->TabIndex = 9;
			this->richTextBox13->Text = L"";
			// 
			// richTextBox14
			// 
			this->richTextBox14->BackColor = System::Drawing::Color::White;
			this->richTextBox14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 40));
			this->richTextBox14->Location = System::Drawing::Point(347, 108);
			this->richTextBox14->MaxLength = 1;
			this->richTextBox14->Name = L"richTextBox14";
			this->richTextBox14->Size = System::Drawing::Size(76, 76);
			this->richTextBox14->TabIndex = 10;
			this->richTextBox14->Text = L"";
			// 
			// richTextBox15
			// 
			this->richTextBox15->BackColor = System::Drawing::Color::White;
			this->richTextBox15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 40));
			this->richTextBox15->Location = System::Drawing::Point(424, 108);
			this->richTextBox15->MaxLength = 1;
			this->richTextBox15->Name = L"richTextBox15";
			this->richTextBox15->Size = System::Drawing::Size(76, 76);
			this->richTextBox15->TabIndex = 11;
			this->richTextBox15->Text = L"";
			// 
			// richTextBox20
			// 
			this->richTextBox20->BackColor = System::Drawing::Color::White;
			this->richTextBox20->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 40));
			this->richTextBox20->Location = System::Drawing::Point(30, 190);
			this->richTextBox20->MaxLength = 1;
			this->richTextBox20->Name = L"richTextBox20";
			this->richTextBox20->Size = System::Drawing::Size(76, 76);
			this->richTextBox20->TabIndex = 12;
			this->richTextBox20->Text = L"";
			// 
			// richTextBox21
			// 
			this->richTextBox21->BackColor = System::Drawing::Color::White;
			this->richTextBox21->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 40));
			this->richTextBox21->Location = System::Drawing::Point(110, 190);
			this->richTextBox21->MaxLength = 1;
			this->richTextBox21->Name = L"richTextBox21";
			this->richTextBox21->Size = System::Drawing::Size(76, 76);
			this->richTextBox21->TabIndex = 13;
			this->richTextBox21->Text = L"";
			// 
			// richTextBox22
			// 
			this->richTextBox22->BackColor = System::Drawing::Color::White;
			this->richTextBox22->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 40));
			this->richTextBox22->Location = System::Drawing::Point(188, 190);
			this->richTextBox22->MaxLength = 1;
			this->richTextBox22->Name = L"richTextBox22";
			this->richTextBox22->Size = System::Drawing::Size(76, 76);
			this->richTextBox22->TabIndex = 14;
			this->richTextBox22->Text = L"";
			// 
			// richTextBox23
			// 
			this->richTextBox23->BackColor = System::Drawing::Color::White;
			this->richTextBox23->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 40));
			this->richTextBox23->Location = System::Drawing::Point(269, 190);
			this->richTextBox23->MaxLength = 1;
			this->richTextBox23->Name = L"richTextBox23";
			this->richTextBox23->Size = System::Drawing::Size(76, 76);
			this->richTextBox23->TabIndex = 15;
			this->richTextBox23->Text = L"";
			// 
			// richTextBox24
			// 
			this->richTextBox24->BackColor = System::Drawing::Color::White;
			this->richTextBox24->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 40));
			this->richTextBox24->Location = System::Drawing::Point(347, 190);
			this->richTextBox24->MaxLength = 1;
			this->richTextBox24->Name = L"richTextBox24";
			this->richTextBox24->Size = System::Drawing::Size(76, 76);
			this->richTextBox24->TabIndex = 16;
			this->richTextBox24->Text = L"";
			// 
			// richTextBox25
			// 
			this->richTextBox25->BackColor = System::Drawing::Color::White;
			this->richTextBox25->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 40));
			this->richTextBox25->Location = System::Drawing::Point(424, 190);
			this->richTextBox25->MaxLength = 1;
			this->richTextBox25->Name = L"richTextBox25";
			this->richTextBox25->Size = System::Drawing::Size(76, 76);
			this->richTextBox25->TabIndex = 17;
			this->richTextBox25->Text = L"";
			// 
			// richTextBox30
			// 
			this->richTextBox30->BackColor = System::Drawing::Color::White;
			this->richTextBox30->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 40));
			this->richTextBox30->Location = System::Drawing::Point(30, 267);
			this->richTextBox30->MaxLength = 1;
			this->richTextBox30->Name = L"richTextBox30";
			this->richTextBox30->Size = System::Drawing::Size(76, 76);
			this->richTextBox30->TabIndex = 18;
			this->richTextBox30->Text = L"";
			// 
			// richTextBox31
			// 
			this->richTextBox31->BackColor = System::Drawing::Color::White;
			this->richTextBox31->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 40));
			this->richTextBox31->Location = System::Drawing::Point(110, 267);
			this->richTextBox31->MaxLength = 1;
			this->richTextBox31->Name = L"richTextBox31";
			this->richTextBox31->Size = System::Drawing::Size(76, 76);
			this->richTextBox31->TabIndex = 19;
			this->richTextBox31->Text = L"";
			// 
			// richTextBox32
			// 
			this->richTextBox32->BackColor = System::Drawing::Color::White;
			this->richTextBox32->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 40));
			this->richTextBox32->Location = System::Drawing::Point(188, 267);
			this->richTextBox32->MaxLength = 1;
			this->richTextBox32->Name = L"richTextBox32";
			this->richTextBox32->Size = System::Drawing::Size(76, 76);
			this->richTextBox32->TabIndex = 20;
			this->richTextBox32->Text = L"";
			// 
			// richTextBox33
			// 
			this->richTextBox33->BackColor = System::Drawing::Color::White;
			this->richTextBox33->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 40));
			this->richTextBox33->Location = System::Drawing::Point(268, 267);
			this->richTextBox33->MaxLength = 1;
			this->richTextBox33->Name = L"richTextBox33";
			this->richTextBox33->Size = System::Drawing::Size(76, 76);
			this->richTextBox33->TabIndex = 21;
			this->richTextBox33->Text = L"";
			// 
			// richTextBox34
			// 
			this->richTextBox34->BackColor = System::Drawing::Color::White;
			this->richTextBox34->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 40));
			this->richTextBox34->Location = System::Drawing::Point(347, 265);
			this->richTextBox34->MaxLength = 1;
			this->richTextBox34->Name = L"richTextBox34";
			this->richTextBox34->Size = System::Drawing::Size(76, 76);
			this->richTextBox34->TabIndex = 22;
			this->richTextBox34->Text = L"";
			// 
			// richTextBox35
			// 
			this->richTextBox35->BackColor = System::Drawing::Color::White;
			this->richTextBox35->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 40));
			this->richTextBox35->Location = System::Drawing::Point(425, 265);
			this->richTextBox35->MaxLength = 1;
			this->richTextBox35->Name = L"richTextBox35";
			this->richTextBox35->Size = System::Drawing::Size(76, 76);
			this->richTextBox35->TabIndex = 23;
			this->richTextBox35->Text = L"";
			// 
			// richTextBox40
			// 
			this->richTextBox40->BackColor = System::Drawing::Color::White;
			this->richTextBox40->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 40));
			this->richTextBox40->Location = System::Drawing::Point(30, 347);
			this->richTextBox40->MaxLength = 1;
			this->richTextBox40->Name = L"richTextBox40";
			this->richTextBox40->Size = System::Drawing::Size(76, 76);
			this->richTextBox40->TabIndex = 24;
			this->richTextBox40->Text = L"";
			// 
			// richTextBox41
			// 
			this->richTextBox41->BackColor = System::Drawing::Color::White;
			this->richTextBox41->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 40));
			this->richTextBox41->Location = System::Drawing::Point(110, 348);
			this->richTextBox41->MaxLength = 1;
			this->richTextBox41->Name = L"richTextBox41";
			this->richTextBox41->Size = System::Drawing::Size(76, 76);
			this->richTextBox41->TabIndex = 25;
			this->richTextBox41->Text = L"";
			// 
			// richTextBox42
			// 
			this->richTextBox42->BackColor = System::Drawing::Color::White;
			this->richTextBox42->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 40));
			this->richTextBox42->Location = System::Drawing::Point(189, 347);
			this->richTextBox42->MaxLength = 1;
			this->richTextBox42->Name = L"richTextBox42";
			this->richTextBox42->Size = System::Drawing::Size(76, 76);
			this->richTextBox42->TabIndex = 26;
			this->richTextBox42->Text = L"";
			// 
			// richTextBox43
			// 
			this->richTextBox43->BackColor = System::Drawing::Color::White;
			this->richTextBox43->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 40));
			this->richTextBox43->Location = System::Drawing::Point(269, 347);
			this->richTextBox43->MaxLength = 1;
			this->richTextBox43->Name = L"richTextBox43";
			this->richTextBox43->Size = System::Drawing::Size(76, 76);
			this->richTextBox43->TabIndex = 27;
			this->richTextBox43->Text = L"";
			// 
			// richTextBox44
			// 
			this->richTextBox44->BackColor = System::Drawing::Color::White;
			this->richTextBox44->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 40));
			this->richTextBox44->Location = System::Drawing::Point(347, 347);
			this->richTextBox44->MaxLength = 1;
			this->richTextBox44->Name = L"richTextBox44";
			this->richTextBox44->Size = System::Drawing::Size(76, 76);
			this->richTextBox44->TabIndex = 28;
			this->richTextBox44->Text = L"";
			// 
			// richTextBox45
			// 
			this->richTextBox45->BackColor = System::Drawing::Color::White;
			this->richTextBox45->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 40));
			this->richTextBox45->Location = System::Drawing::Point(424, 347);
			this->richTextBox45->MaxLength = 1;
			this->richTextBox45->Name = L"richTextBox45";
			this->richTextBox45->Size = System::Drawing::Size(76, 76);
			this->richTextBox45->TabIndex = 29;
			this->richTextBox45->Text = L"";
			// 
			// richTextBox50
			// 
			this->richTextBox50->BackColor = System::Drawing::Color::White;
			this->richTextBox50->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 40));
			this->richTextBox50->Location = System::Drawing::Point(30, 425);
			this->richTextBox50->MaxLength = 1;
			this->richTextBox50->Name = L"richTextBox50";
			this->richTextBox50->Size = System::Drawing::Size(76, 76);
			this->richTextBox50->TabIndex = 30;
			this->richTextBox50->Text = L"";
			// 
			// richTextBox51
			// 
			this->richTextBox51->BackColor = System::Drawing::Color::White;
			this->richTextBox51->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 40));
			this->richTextBox51->Location = System::Drawing::Point(110, 425);
			this->richTextBox51->MaxLength = 1;
			this->richTextBox51->Name = L"richTextBox51";
			this->richTextBox51->Size = System::Drawing::Size(76, 76);
			this->richTextBox51->TabIndex = 31;
			this->richTextBox51->Text = L"";
			// 
			// richTextBox52
			// 
			this->richTextBox52->BackColor = System::Drawing::Color::White;
			this->richTextBox52->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 40));
			this->richTextBox52->Location = System::Drawing::Point(189, 425);
			this->richTextBox52->MaxLength = 1;
			this->richTextBox52->Name = L"richTextBox52";
			this->richTextBox52->Size = System::Drawing::Size(76, 76);
			this->richTextBox52->TabIndex = 32;
			this->richTextBox52->Text = L"";
			// 
			// richTextBox53
			// 
			this->richTextBox53->BackColor = System::Drawing::Color::White;
			this->richTextBox53->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 40));
			this->richTextBox53->Location = System::Drawing::Point(269, 425);
			this->richTextBox53->MaxLength = 1;
			this->richTextBox53->Name = L"richTextBox53";
			this->richTextBox53->Size = System::Drawing::Size(76, 76);
			this->richTextBox53->TabIndex = 33;
			this->richTextBox53->Text = L"";
			// 
			// richTextBox54
			// 
			this->richTextBox54->BackColor = System::Drawing::Color::White;
			this->richTextBox54->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 40));
			this->richTextBox54->Location = System::Drawing::Point(345, 424);
			this->richTextBox54->MaxLength = 1;
			this->richTextBox54->Name = L"richTextBox54";
			this->richTextBox54->Size = System::Drawing::Size(76, 76);
			this->richTextBox54->TabIndex = 34;
			this->richTextBox54->Text = L"";
			// 
			// richTextBox55
			// 
			this->richTextBox55->BackColor = System::Drawing::Color::White;
			this->richTextBox55->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 40));
			this->richTextBox55->Location = System::Drawing::Point(425, 425);
			this->richTextBox55->MaxLength = 1;
			this->richTextBox55->Name = L"richTextBox55";
			this->richTextBox55->Size = System::Drawing::Size(76, 76);
			this->richTextBox55->TabIndex = 35;
			this->richTextBox55->Text = L"";
			// 
			// solveButton
			// 
			this->solveButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(177)));
			this->solveButton->Location = System::Drawing::Point(380, 520);
			this->solveButton->Name = L"solveButton";
			this->solveButton->Size = System::Drawing::Size(121, 37);
			this->solveButton->TabIndex = 36;
			this->solveButton->Text = L"Solve";
			this->solveButton->UseVisualStyleBackColor = true;
			this->solveButton->Click += gcnew System::EventHandler(this, &MainForm::solveButtonClicked);
			// 
			// resetButton
			// 
			this->resetButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(177)));
			this->resetButton->Location = System::Drawing::Point(58, 520);
			this->resetButton->Name = L"resetButton";
			this->resetButton->Size = System::Drawing::Size(121, 37);
			this->resetButton->TabIndex = 37;
			this->resetButton->Text = L"Reset";
			this->resetButton->UseVisualStyleBackColor = true;
			this->resetButton->Click += gcnew System::EventHandler(this, &MainForm::resetButtonClicked);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(177)));
			this->label1->Location = System::Drawing::Point(61, 571);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(60, 20);
			this->label1->TabIndex = 38;
			this->label1->Text = L"Status:";
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox1->Location = System::Drawing::Point(17, 17);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(496, 497);
			this->pictureBox1->TabIndex = 39;
			this->pictureBox1->TabStop = false;
			// 
			// poolSizeComboBox
			// 
			this->poolSizeComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->poolSizeComboBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(177)));
			this->poolSizeComboBox->FormattingEnabled = true;
			this->poolSizeComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"50", L"100", L"150", L"200", L"250" });
			this->poolSizeComboBox->Location = System::Drawing::Point(559, 120);
			this->poolSizeComboBox->Name = L"poolSizeComboBox";
			this->poolSizeComboBox->Size = System::Drawing::Size(62, 24);
			this->poolSizeComboBox->TabIndex = 40;
			// 
			// mutationPercentageComboBox
			// 
			this->mutationPercentageComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->mutationPercentageComboBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(177)));
			this->mutationPercentageComboBox->FormattingEnabled = true;
			this->mutationPercentageComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(7) {
				L"3%", L"5%", L"10%", L"20%",
					L"25%", L"30%", L"50%"
			});
			this->mutationPercentageComboBox->Location = System::Drawing::Point(559, 190);
			this->mutationPercentageComboBox->Name = L"mutationPercentageComboBox";
			this->mutationPercentageComboBox->Size = System::Drawing::Size(62, 24);
			this->mutationPercentageComboBox->TabIndex = 41;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(553, 172);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(77, 13);
			this->label2->TabIndex = 42;
			this->label2->Text = L"Mutation Rate:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(562, 102);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(54, 13);
			this->label3->TabIndex = 43;
			this->label3->Text = L"Pool Size:";
			// 
			// easyExampleButton
			// 
			this->easyExampleButton->Location = System::Drawing::Point(535, 265);
			this->easyExampleButton->Name = L"easyExampleButton";
			this->easyExampleButton->Size = System::Drawing::Size(120, 23);
			this->easyExampleButton->TabIndex = 45;
			this->easyExampleButton->Text = L"Add Easy Example";
			this->easyExampleButton->UseVisualStyleBackColor = true;
			this->easyExampleButton->Click += gcnew System::EventHandler(this, &MainForm::easyExampleButton_Click);
			// 
			// StandardExampleButton
			// 
			this->StandardExampleButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(177)));
			this->StandardExampleButton->Location = System::Drawing::Point(535, 307);
			this->StandardExampleButton->Name = L"StandardExampleButton";
			this->StandardExampleButton->Size = System::Drawing::Size(120, 23);
			this->StandardExampleButton->TabIndex = 46;
			this->StandardExampleButton->Text = L"Add Medium Example";
			this->StandardExampleButton->UseVisualStyleBackColor = true;
			this->StandardExampleButton->Click += gcnew System::EventHandler(this, &MainForm::StandardExampleButton_Click);
			// 
			// hardExampleButton
			// 
			this->hardExampleButton->Location = System::Drawing::Point(535, 348);
			this->hardExampleButton->Name = L"hardExampleButton";
			this->hardExampleButton->Size = System::Drawing::Size(120, 23);
			this->hardExampleButton->TabIndex = 47;
			this->hardExampleButton->Text = L"Add Hard Example";
			this->hardExampleButton->UseVisualStyleBackColor = true;
			this->hardExampleButton->Click += gcnew System::EventHandler(this, &MainForm::hardExampleButton_Click);
			// 
			// cheatBox
			// 
			this->cheatBox->AutoSize = true;
			this->cheatBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cheatBox->Location = System::Drawing::Point(556, 385);
			this->cheatBox->Name = L"cheatBox";
			this->cheatBox->Size = System::Drawing::Size(64, 21);
			this->cheatBox->TabIndex = 48;
			this->cheatBox->Text = L"Cheat";
			this->cheatBox->UseVisualStyleBackColor = true;
			this->cheatBox->CheckedChanged += gcnew System::EventHandler(this, &MainForm::CheatBox_CheckedChanged);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ClientSize = System::Drawing::Size(674, 609);
			this->Controls->Add(this->cheatBox);
			this->Controls->Add(this->hardExampleButton);
			this->Controls->Add(this->StandardExampleButton);
			this->Controls->Add(this->easyExampleButton);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->mutationPercentageComboBox);
			this->Controls->Add(this->poolSizeComboBox);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->resetButton);
			this->Controls->Add(this->solveButton);
			this->Controls->Add(this->richTextBox00);
			this->Controls->Add(this->richTextBox01);
			this->Controls->Add(this->richTextBox02);
			this->Controls->Add(this->richTextBox03);
			this->Controls->Add(this->richTextBox04);
			this->Controls->Add(this->richTextBox05);
			this->Controls->Add(this->richTextBox10);
			this->Controls->Add(this->richTextBox11);
			this->Controls->Add(this->richTextBox12);
			this->Controls->Add(this->richTextBox13);
			this->Controls->Add(this->richTextBox14);
			this->Controls->Add(this->richTextBox15);
			this->Controls->Add(this->richTextBox20);
			this->Controls->Add(this->richTextBox21);
			this->Controls->Add(this->richTextBox22);
			this->Controls->Add(this->richTextBox23);
			this->Controls->Add(this->richTextBox24);
			this->Controls->Add(this->richTextBox25);
			this->Controls->Add(this->richTextBox30);
			this->Controls->Add(this->richTextBox31);
			this->Controls->Add(this->richTextBox32);
			this->Controls->Add(this->richTextBox33);
			this->Controls->Add(this->richTextBox34);
			this->Controls->Add(this->richTextBox35);
			this->Controls->Add(this->richTextBox40);
			this->Controls->Add(this->richTextBox41);
			this->Controls->Add(this->richTextBox42);
			this->Controls->Add(this->richTextBox43);
			this->Controls->Add(this->richTextBox44);
			this->Controls->Add(this->richTextBox45);
			this->Controls->Add(this->richTextBox50);
			this->Controls->Add(this->richTextBox51);
			this->Controls->Add(this->richTextBox52);
			this->Controls->Add(this->richTextBox53);
			this->Controls->Add(this->richTextBox54);
			this->Controls->Add(this->richTextBox55);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MainForm";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		std::vector<std::vector<int>> getExpertExample()
		{
			std::vector<std::vector<int>> expertMatrix(6, std::vector<int>(6));
			expertMatrix[0][2] = 4;
			expertMatrix[1][1] = 6; expertMatrix[1][5] = 5;
			expertMatrix[2][1] = 1;	expertMatrix[2][3] = 3;	expertMatrix[2][4] = 4;
			expertMatrix[3][0] = 4; expertMatrix[3][2] = 6; expertMatrix[3][4] = 2;
			expertMatrix[4][1] = 4;	expertMatrix[4][2] = 1; expertMatrix[4][5] = 2;
			expertMatrix[5][3] = 1; expertMatrix[5][4] = 5;
			return expertMatrix;
		}

		std::vector<std::vector<int>> getStandardExample()
		{
			std::vector<std::vector<int>> standardExample(6, std::vector<int>(6));
			standardExample[0][0] = 3; standardExample[0][2] = 2; standardExample[0][4] = 6; standardExample[0][5] = 4;
			standardExample[1][1] = 5; standardExample[1][2] = 6; standardExample[1][5] = 3;
			standardExample[2][1] = 6; standardExample[2][2] = 4;
			standardExample[3][0] = 1; standardExample[3][3] = 4; standardExample[3][5] = 6;
			standardExample[4][0] = 6; standardExample[4][2] = 5; standardExample[4][5] = 2;
			standardExample[5][1] = 3; standardExample[5][2] = 1; standardExample[5][4] = 4;

			return standardExample;
		}

		std::vector<std::vector<int>> getEasyExample()
		{
			std::vector<std::vector<int>> easyMatrix(6, std::vector<int>(6));
			easyMatrix[0][0] = 5; easyMatrix[0][4] = 4; easyMatrix[0][5] = 3;
			easyMatrix[1][1] = 4; easyMatrix[1][2] = 2; easyMatrix[1][5] = 6;
			easyMatrix[2][1] = 2; easyMatrix[2][2] = 1; easyMatrix[2][3] = 6; easyMatrix[2][5] = 5;
			easyMatrix[3][0] = 6; easyMatrix[3][2] = 5;	easyMatrix[3][3] = 4; easyMatrix[3][4] = 1; easyMatrix[3][5] = 2;
			easyMatrix[4][0] = 1; easyMatrix[4][3] = 5; easyMatrix[4][4] = 2;
			easyMatrix[5][0] = 2; easyMatrix[5][1] = 5; easyMatrix[5][2] = 4; easyMatrix[5][5] = 1;
			return easyMatrix;

		}
		void displaySudokuMatrix(std::vector<std::vector<int>> sudokuMatrix, std::vector<std::vector<int>> initFilledPlaces)
		{
			for (int i = 0; i < 6; i++)
			{
				for (int j = 0; j < 6; j++)
				{
					if (sudokuMatrix[i][j] != 0)
					{
						if (example)
							textBoxMatrix[i, j]->BackColor = System::Drawing::Color::DarkGreen;
						if ((isAnswer) && (!initFilledPlaces[i][j]))
							textBoxMatrix[i, j]->BackColor = System::Drawing::Color::LimeGreen;
						textBoxMatrix[i, j]->Text = sudokuMatrix[i][j].ToString();
						textBoxMatrix[i, j]->Refresh();

					}
					else
					{
						textBoxMatrix[i, j]->Text = L"";
						textBoxMatrix[i, j]->BackColor = System::Drawing::SystemColors::Control;
					}

				}
			}
			example = 0;
		}


		void solveButtonClicked(Object^ sender, EventArgs^ e)
		{
			isAnswer = 0;
			std::vector<std::vector<int>> sudokuMatrix(6, std::vector<int>(6));
			std::vector<std::vector<int>> initFilledPlaces(6, std::vector<int>(6));
			for (int i = 0; i < 6; i++) //Check validity of input, and move to a integer sudoku matrix 6x6
			{
				for (int j = 0; j < 6; j++)
				{
					if (textBoxMatrix[i, j]->Text != "")
					{
						if ((textBoxMatrix[i, j]->Text[0] < '1') || (textBoxMatrix[i, j]->Text[0] > '6'))
						{
							label1->Text = "Status: Please insert only numbers between 1-6";
							break;
						}
						else
						{
							sudokuMatrix[i][j] = System::Int32::Parse(textBoxMatrix[i, j]->Text);
							initFilledPlaces[i][j] = 1;
						}
					}
					else
					{
						sudokuMatrix[i][j] = 0;
					}
				}
			}
			std::vector<int>  poolSizeList = { 50,100,150,200,250 };
			std::vector<int>  mutationPercentList = { 3, 5,10,20,25,30,50 };
			poolSize = System::Int32::Parse(poolSizeComboBox->SelectedItem->ToString());
			mutationPercent = mutationPercentList[mutationPercentageComboBox->SelectedIndex];
			//ticks = 0;
			std::vector<std::vector<int>> ansMatrix = solveSudoku(sudokuMatrix, initFilledPlaces, poolSize, mutationPercent);
			isAnswer = 1;
			displaySudokuMatrix(ansMatrix, initFilledPlaces);
			label1->ForeColor = System::Drawing::Color::Green;
			label1->Refresh();
		}

		std::vector<std::vector<int>> solveSudoku(std::vector<std::vector<int>> sudokuMatrix,
			std::vector<std::vector<int>> initFilledPlaces, int poolSize, int mutationPercent)
		{
			if (cheatBox->Checked)
				Calculations::cheat = true;
			srand(time(NULL));
			std::vector<Chromosome> pool = Calculations::generateRandomPool(sudokuMatrix, poolSize);
			Chromosome bestFitness = pool[0];
			double bestFitnessValue = pool[0].fitness;
			displaySudokuMatrix(bestFitness.sudokuMatrix, initFilledPlaces);
			label1->Text = "Status: Min Fitness=" + System::Convert::ToInt32(bestFitnessValue) + "   Generation: 0";
			label1->Refresh();
			int countGenerations = 0;
			while (bestFitness.fitness != 0)
			{
				/*if (countGenerations == 25)
				{
					pool = Calculations::generateRandomPool(sudokuMatrix, poolSize);
					bestFitness = pool[0];
					bestFitnessValue = pool[0].fitness;
				}*/

				double weightSum = 0;
				std::vector<double>weights;
				for (int i = 0; i < pool.size(); i++)
				{
					weightSum += (1 / pool[i].fitness) * pool[pool.size() - 1].fitness;
					weights.push_back((1 / pool[i].fitness) * pool[pool.size() - 1].fitness);
				}
				pool.push_back(Calculations::mutate(pool[0], initFilledPlaces));
				countGenerations++;
				Random rand;
				std::vector<Chromosome> poolGeneration;
				while (poolGeneration.size() < poolSize)
				{

					int crossType = rand.Next(1, 11);
					int rand1 = 0, rand2 = 0;
					while (rand1 == rand2)
					{
						rand1 = Calculations::randomPickByWeight(pool,weights ,weightSum);
						rand2 = Calculations::randomPickByWeight(pool, weights, weightSum);
					}
					Chromosome c();
					if (crossType < 9) //80% crossover Cols.
					{
						Chromosome c = Calculations::crossoverCols(pool[rand1], pool[rand2]);
						poolGeneration.push_back(c);
						if (rand.Next(0, 100) % 100 < mutationPercent)
						{
							poolGeneration.push_back(Calculations::mutate(c, initFilledPlaces));
						}
						else
							poolGeneration.push_back(c);
					}
					else
					{
						Chromosome c = Calculations::crossoverRows(pool[rand1], pool[rand2]);
						if (rand.Next(0, 100) % 100 < mutationPercent)
						{
							poolGeneration.push_back(Calculations::mutate(c, initFilledPlaces));
						}
						else
							poolGeneration.push_back(c);
					}


				}
				ageLimit = poolSize / 10;
				//remove old genes
				for (int i = 0; i < pool.size() / 10; i++)
				{
					pool[i].age++;
					if (pool[i].age >= ageLimit)
					{
						pool.erase(pool.begin() + i);
						i--;
					}

				}
				pool.push_back(Calculations::mutate(pool[0], initFilledPlaces));
				pool.insert(pool.end(), poolGeneration.begin(), poolGeneration.end());
				std::sort(pool.begin(), pool.end());

				pool.erase(pool.begin() + poolSize - 5, pool.end());
				for (int i = 0; i < 5; i++)
					pool.push_back(Calculations::generateRandomChromosome(sudokuMatrix));
				bestFitness = pool[0];
				displaySudokuMatrix(bestFitness.sudokuMatrix, initFilledPlaces);
				bestFitnessValue = bestFitness.fitness;
				label1->Text = "Status: Min Fitness=" + System::Convert::ToInt32(bestFitnessValue) + "   Generation:" + countGenerations;
				label1->Refresh();
			}
			return bestFitness.sudokuMatrix;			//found solution
		}



		void resetButtonClicked(Object^ sender, EventArgs^ e)
		{

			for (int i = 0; i < 6; i++)
				for (int j = 0; j < 6; j++)
				{
					textBoxMatrix[i, j]->Text = L"";
				}
			label1->Text = "Status:";
		}


#pragma endregion	

	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e)
	{
		poolSizeComboBox->SelectedIndex = 2;
		mutationPercentageComboBox->SelectedIndex = 2;
		textBoxMatrix[0, 0] = richTextBox00;
		textBoxMatrix[0, 1] = richTextBox01;
		textBoxMatrix[0, 2] = richTextBox02;
		textBoxMatrix[0, 3] = richTextBox03;
		textBoxMatrix[0, 4] = richTextBox04;
		textBoxMatrix[0, 5] = richTextBox05;
		textBoxMatrix[1, 0] = richTextBox10;
		textBoxMatrix[1, 1] = richTextBox11;
		textBoxMatrix[1, 2] = richTextBox12;
		textBoxMatrix[1, 3] = richTextBox13;
		textBoxMatrix[1, 4] = richTextBox14;
		textBoxMatrix[1, 5] = richTextBox15;
		textBoxMatrix[2, 0] = richTextBox20;
		textBoxMatrix[2, 1] = richTextBox21;
		textBoxMatrix[2, 2] = richTextBox22;
		textBoxMatrix[2, 3] = richTextBox23;
		textBoxMatrix[2, 4] = richTextBox24;
		textBoxMatrix[2, 5] = richTextBox25;
		textBoxMatrix[3, 0] = richTextBox30;
		textBoxMatrix[3, 1] = richTextBox31;
		textBoxMatrix[3, 2] = richTextBox32;
		textBoxMatrix[3, 3] = richTextBox33;
		textBoxMatrix[3, 4] = richTextBox34;
		textBoxMatrix[3, 5] = richTextBox35;
		textBoxMatrix[4, 0] = richTextBox40;
		textBoxMatrix[4, 1] = richTextBox41;
		textBoxMatrix[4, 2] = richTextBox42;
		textBoxMatrix[4, 3] = richTextBox43;
		textBoxMatrix[4, 4] = richTextBox44;
		textBoxMatrix[4, 5] = richTextBox45;
		textBoxMatrix[5, 0] = richTextBox50;
		textBoxMatrix[5, 1] = richTextBox51;
		textBoxMatrix[5, 2] = richTextBox52;
		textBoxMatrix[5, 3] = richTextBox53;
		textBoxMatrix[5, 4] = richTextBox54;
		textBoxMatrix[5, 5] = richTextBox55;
		for (int i = 0; i < 6; i++)
			for (int j = 0; j < 6; j++)

			{
				textBoxMatrix[i, j]->SelectAll();
				textBoxMatrix[i, j]->SelectionAlignment = HorizontalAlignment(2);
				textBoxMatrix[i, j]->DeselectAll();
				textBoxMatrix[i, j]->Refresh();
			}
	}
	private: System::Void easyExampleButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		example = 1;
		displaySudokuMatrix(getEasyExample(), getEasyExample());
	}
	private: System::Void StandardExampleButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		example = 1;
		displaySudokuMatrix(getStandardExample(), getStandardExample());
	}
	private: System::Void hardExampleButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		example = 1;
		displaySudokuMatrix(getExpertExample(), getExpertExample());
	}

	private: System::Void CheatBox_CheckedChanged(System::Object^ sender, System::EventArgs^ e) 
	{

	}
};
}

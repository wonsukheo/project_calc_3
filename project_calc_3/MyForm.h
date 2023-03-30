#pragma once

namespace projectcalc3 {

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
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			mLhInput = 0;
			mRhInput = 0;
			mResult = 0;
			mDecimalFlag = false;
			mOpFlag = false;
			mOp = '\0';
			mNegPow = 1;
			mDisplayString = System::String::Empty;
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
	private: System::Windows::Forms::Button^ numPad0;
	private: System::Windows::Forms::Button^ numPad1;
	private: System::Windows::Forms::Button^ numPad2;
	private: System::Windows::Forms::Button^ numPad3;
	private: System::Windows::Forms::Button^ numPad4;
	private: System::Windows::Forms::Button^ numPad5;
	private: System::Windows::Forms::Button^ numPad6;
	private: System::Windows::Forms::Button^ numPad7;
	private: System::Windows::Forms::Button^ numPad8;
	private: System::Windows::Forms::Button^ numPad9;
	private: System::Windows::Forms::Button^ opClr;
	private: System::Windows::Forms::Button^ opDiv;
	private: System::Windows::Forms::Button^ opMult;
	private: System::Windows::Forms::Button^ opErase;
	private: System::Windows::Forms::Button^ opAdd;
	private: System::Windows::Forms::Button^ opDecimal;
	private: System::Windows::Forms::Button^ opNeg;
	private: System::Windows::Forms::Button^ opEnter;
	private: System::Windows::Forms::Button^ opSub;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;
		double mLhInput;
		double mRhInput;
		double mResult;
		bool mDecimalFlag;
		bool mOpFlag;
		char mOp;
		unsigned int mNegPow;
	private: System::Windows::Forms::TextBox^ display;


		String^ mDisplayString;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		/// 
		void updateInputHelper(double% input, unsigned int numPadInput) {

			if (mDecimalFlag) {
				input += numPadInput / Math::Pow(10, mNegPow);
				++mNegPow;
			}
			else {
				input *= 10;
				input += numPadInput;
			}
		}

		void updateInput(unsigned int numPadInput)
		{
			char c = 0;
			mDisplayString += c + numPadInput;
			display->Text = mDisplayString;

			if (mOpFlag) {
				updateInputHelper(this->mRhInput, numPadInput);
			}
			else {
				updateInputHelper(this->mLhInput, numPadInput);
			}
		}

		void reset()
		{
			mLhInput = 0;
			mRhInput = 0;
			mResult = 0;
			mDecimalFlag = false;
			mOpFlag = false;
			mOp = '\0';
			mNegPow = 1;
			mDisplayString = System::String::Empty;
		}

		void InitializeComponent(void)
		{
			this->numPad0 = (gcnew System::Windows::Forms::Button());
			this->numPad1 = (gcnew System::Windows::Forms::Button());
			this->numPad2 = (gcnew System::Windows::Forms::Button());
			this->numPad3 = (gcnew System::Windows::Forms::Button());
			this->numPad4 = (gcnew System::Windows::Forms::Button());
			this->numPad5 = (gcnew System::Windows::Forms::Button());
			this->numPad6 = (gcnew System::Windows::Forms::Button());
			this->numPad7 = (gcnew System::Windows::Forms::Button());
			this->numPad8 = (gcnew System::Windows::Forms::Button());
			this->numPad9 = (gcnew System::Windows::Forms::Button());
			this->opClr = (gcnew System::Windows::Forms::Button());
			this->opDiv = (gcnew System::Windows::Forms::Button());
			this->opMult = (gcnew System::Windows::Forms::Button());
			this->opErase = (gcnew System::Windows::Forms::Button());
			this->opAdd = (gcnew System::Windows::Forms::Button());
			this->opDecimal = (gcnew System::Windows::Forms::Button());
			this->opNeg = (gcnew System::Windows::Forms::Button());
			this->opEnter = (gcnew System::Windows::Forms::Button());
			this->opSub = (gcnew System::Windows::Forms::Button());
			this->display = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// numPad0
			// 
			this->numPad0->Location = System::Drawing::Point(12, 389);
			this->numPad0->Name = L"numPad0";
			this->numPad0->Size = System::Drawing::Size(55, 55);
			this->numPad0->TabIndex = 0;
			this->numPad0->Text = L"0";
			this->numPad0->UseVisualStyleBackColor = true;
			this->numPad0->Click += gcnew System::EventHandler(this, &MyForm::numPad0_Click);
			// 
			// numPad1
			// 
			this->numPad1->Location = System::Drawing::Point(12, 328);
			this->numPad1->Name = L"numPad1";
			this->numPad1->Size = System::Drawing::Size(55, 55);
			this->numPad1->TabIndex = 1;
			this->numPad1->Text = L"1";
			this->numPad1->UseVisualStyleBackColor = true;
			this->numPad1->Click += gcnew System::EventHandler(this, &MyForm::numPad1_Click);
			// 
			// numPad2
			// 
			this->numPad2->Location = System::Drawing::Point(73, 328);
			this->numPad2->Name = L"numPad2";
			this->numPad2->Size = System::Drawing::Size(55, 55);
			this->numPad2->TabIndex = 2;
			this->numPad2->Text = L"2";
			this->numPad2->UseVisualStyleBackColor = true;
			this->numPad2->Click += gcnew System::EventHandler(this, &MyForm::numPad2_Click);
			// 
			// numPad3
			// 
			this->numPad3->Location = System::Drawing::Point(134, 328);
			this->numPad3->Name = L"numPad3";
			this->numPad3->Size = System::Drawing::Size(55, 55);
			this->numPad3->TabIndex = 3;
			this->numPad3->Text = L"3";
			this->numPad3->UseVisualStyleBackColor = true;
			this->numPad3->Click += gcnew System::EventHandler(this, &MyForm::numPad3_Click);
			// 
			// numPad4
			// 
			this->numPad4->Location = System::Drawing::Point(12, 267);
			this->numPad4->Name = L"numPad4";
			this->numPad4->Size = System::Drawing::Size(55, 55);
			this->numPad4->TabIndex = 4;
			this->numPad4->Text = L"4";
			this->numPad4->UseVisualStyleBackColor = true;
			this->numPad4->Click += gcnew System::EventHandler(this, &MyForm::numPad4_Click);
			// 
			// numPad5
			// 
			this->numPad5->Location = System::Drawing::Point(73, 267);
			this->numPad5->Name = L"numPad5";
			this->numPad5->Size = System::Drawing::Size(55, 55);
			this->numPad5->TabIndex = 5;
			this->numPad5->Text = L"5";
			this->numPad5->UseVisualStyleBackColor = true;
			this->numPad5->Click += gcnew System::EventHandler(this, &MyForm::numPad5_Click);
			// 
			// numPad6
			// 
			this->numPad6->Location = System::Drawing::Point(134, 267);
			this->numPad6->Name = L"numPad6";
			this->numPad6->Size = System::Drawing::Size(55, 55);
			this->numPad6->TabIndex = 6;
			this->numPad6->Text = L"6";
			this->numPad6->UseVisualStyleBackColor = true;
			this->numPad6->Click += gcnew System::EventHandler(this, &MyForm::numPad6_Click);
			// 
			// numPad7
			// 
			this->numPad7->Location = System::Drawing::Point(12, 206);
			this->numPad7->Name = L"numPad7";
			this->numPad7->Size = System::Drawing::Size(55, 55);
			this->numPad7->TabIndex = 7;
			this->numPad7->Text = L"7";
			this->numPad7->UseVisualStyleBackColor = true;
			this->numPad7->Click += gcnew System::EventHandler(this, &MyForm::numPad7_Click);
			// 
			// numPad8
			// 
			this->numPad8->Location = System::Drawing::Point(73, 206);
			this->numPad8->Name = L"numPad8";
			this->numPad8->Size = System::Drawing::Size(55, 55);
			this->numPad8->TabIndex = 8;
			this->numPad8->Text = L"8";
			this->numPad8->UseVisualStyleBackColor = true;
			this->numPad8->Click += gcnew System::EventHandler(this, &MyForm::numPad8_Click);
			// 
			// numPad9
			// 
			this->numPad9->Location = System::Drawing::Point(134, 206);
			this->numPad9->Name = L"numPad9";
			this->numPad9->Size = System::Drawing::Size(55, 55);
			this->numPad9->TabIndex = 9;
			this->numPad9->Text = L"9";
			this->numPad9->UseVisualStyleBackColor = true;
			this->numPad9->Click += gcnew System::EventHandler(this, &MyForm::numPad9_Click);
			// 
			// opClr
			// 
			this->opClr->Location = System::Drawing::Point(12, 145);
			this->opClr->Name = L"opClr";
			this->opClr->Size = System::Drawing::Size(55, 55);
			this->opClr->TabIndex = 10;
			this->opClr->Text = L"clr";
			this->opClr->UseVisualStyleBackColor = true;
			// 
			// opDiv
			// 
			this->opDiv->Location = System::Drawing::Point(73, 145);
			this->opDiv->Name = L"opDiv";
			this->opDiv->Size = System::Drawing::Size(55, 55);
			this->opDiv->TabIndex = 11;
			this->opDiv->Text = L"/";
			this->opDiv->UseVisualStyleBackColor = true;
			this->opDiv->Click += gcnew System::EventHandler(this, &MyForm::opDiv_Click);
			// 
			// opMult
			// 
			this->opMult->Location = System::Drawing::Point(134, 145);
			this->opMult->Name = L"opMult";
			this->opMult->Size = System::Drawing::Size(55, 55);
			this->opMult->TabIndex = 12;
			this->opMult->Text = L"*";
			this->opMult->UseVisualStyleBackColor = true;
			this->opMult->Click += gcnew System::EventHandler(this, &MyForm::opMult_Click);
			// 
			// opErase
			// 
			this->opErase->Location = System::Drawing::Point(195, 145);
			this->opErase->Name = L"opErase";
			this->opErase->Size = System::Drawing::Size(55, 55);
			this->opErase->TabIndex = 13;
			this->opErase->Text = L"<-";
			this->opErase->UseVisualStyleBackColor = true;
			// 
			// opAdd
			// 
			this->opAdd->Location = System::Drawing::Point(195, 206);
			this->opAdd->Name = L"opAdd";
			this->opAdd->Size = System::Drawing::Size(55, 55);
			this->opAdd->TabIndex = 14;
			this->opAdd->Text = L"+";
			this->opAdd->UseVisualStyleBackColor = true;
			this->opAdd->Click += gcnew System::EventHandler(this, &MyForm::opAdd_Click);
			// 
			// opDecimal
			// 
			this->opDecimal->Location = System::Drawing::Point(73, 388);
			this->opDecimal->Name = L"opDecimal";
			this->opDecimal->Size = System::Drawing::Size(55, 55);
			this->opDecimal->TabIndex = 15;
			this->opDecimal->Text = L".";
			this->opDecimal->UseVisualStyleBackColor = true;
			this->opDecimal->Click += gcnew System::EventHandler(this, &MyForm::opDecimal_Click);
			// 
			// opNeg
			// 
			this->opNeg->Location = System::Drawing::Point(134, 389);
			this->opNeg->Name = L"opNeg";
			this->opNeg->Size = System::Drawing::Size(55, 55);
			this->opNeg->TabIndex = 16;
			this->opNeg->Text = L"(-)";
			this->opNeg->UseVisualStyleBackColor = true;
			this->opNeg->Click += gcnew System::EventHandler(this, &MyForm::opNeg_Click);
			// 
			// opEnter
			// 
			this->opEnter->Location = System::Drawing::Point(195, 328);
			this->opEnter->Name = L"opEnter";
			this->opEnter->Size = System::Drawing::Size(55, 116);
			this->opEnter->TabIndex = 17;
			this->opEnter->Text = L"=";
			this->opEnter->UseVisualStyleBackColor = true;
			this->opEnter->Click += gcnew System::EventHandler(this, &MyForm::opEnter_Click);
			// 
			// opSub
			// 
			this->opSub->Location = System::Drawing::Point(195, 267);
			this->opSub->Name = L"opSub";
			this->opSub->Size = System::Drawing::Size(55, 55);
			this->opSub->TabIndex = 18;
			this->opSub->Text = L"-";
			this->opSub->UseVisualStyleBackColor = true;
			this->opSub->Click += gcnew System::EventHandler(this, &MyForm::opSub_Click);
			// 
			// display
			// 
			this->display->Location = System::Drawing::Point(13, 43);
			this->display->Multiline = true;
			this->display->Name = L"display";
			this->display->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->display->Size = System::Drawing::Size(237, 96);
			this->display->TabIndex = 19;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(413, 453);
			this->Controls->Add(this->display);
			this->Controls->Add(this->opSub);
			this->Controls->Add(this->opEnter);
			this->Controls->Add(this->opNeg);
			this->Controls->Add(this->opDecimal);
			this->Controls->Add(this->opAdd);
			this->Controls->Add(this->opErase);
			this->Controls->Add(this->opMult);
			this->Controls->Add(this->opDiv);
			this->Controls->Add(this->opClr);
			this->Controls->Add(this->numPad9);
			this->Controls->Add(this->numPad8);
			this->Controls->Add(this->numPad7);
			this->Controls->Add(this->numPad6);
			this->Controls->Add(this->numPad5);
			this->Controls->Add(this->numPad4);
			this->Controls->Add(this->numPad3);
			this->Controls->Add(this->numPad2);
			this->Controls->Add(this->numPad1);
			this->Controls->Add(this->numPad0);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void numPad1_Click(System::Object^ sender, System::EventArgs^ e) {
		updateInput(1);
	}
	private: System::Void numPad2_Click(System::Object^ sender, System::EventArgs^ e) {
		updateInput(2);
	}
	private: System::Void numPad3_Click(System::Object^ sender, System::EventArgs^ e) {
		updateInput(3);
	}
	private: System::Void numPad4_Click(System::Object^ sender, System::EventArgs^ e) {
		updateInput(4);
	}
	private: System::Void numPad5_Click(System::Object^ sender, System::EventArgs^ e) {
		updateInput(5);
	}
	private: System::Void numPad6_Click(System::Object^ sender, System::EventArgs^ e) {
		updateInput(6);
	}
	private: System::Void numPad7_Click(System::Object^ sender, System::EventArgs^ e) {
		updateInput(7);
	}
	private: System::Void numPad8_Click(System::Object^ sender, System::EventArgs^ e) {
		updateInput(8);
	}
	private: System::Void numPad9_Click(System::Object^ sender, System::EventArgs^ e) {
		updateInput(9);
	}
	private: System::Void numPad0_Click(System::Object^ sender, System::EventArgs^ e) {
		updateInput(0);
	}
	private: System::Void opDecimal_Click(System::Object^ sender, System::EventArgs^ e) {
		mDecimalFlag = true;
	}
	private: System::Void opNeg_Click(System::Object^ sender, System::EventArgs^ e) {
		(mOpFlag ? this->mRhInput *= -1 : this->mLhInput *= -1);

		mDisplayString->Insert(0, "-");
		display->Text = mDisplayString;
	}
	private: System::Void opDiv_Click(System::Object^ sender, System::EventArgs^ e) {
		mOpFlag = true;
		mOp = '/';

		mDisplayString += " / ";
		display->Text = mDisplayString;
	}
	private: System::Void opMult_Click(System::Object^ sender, System::EventArgs^ e) {
		mOpFlag = true;
		mOp = '*';

		mDisplayString += " * ";
		display->Text = mDisplayString;
	}
	private: System::Void opAdd_Click(System::Object^ sender, System::EventArgs^ e) {
		mOpFlag = true;
		mOp = '+';

		mDisplayString += " + ";
		display->Text = mDisplayString;
	}
	private: System::Void opSub_Click(System::Object^ sender, System::EventArgs^ e) {
		mOpFlag = true;
		mOp = '-';

		mDisplayString += " - ";
		display->Text = mDisplayString;
	}
	private: System::Void opEnter_Click(System::Object^ sender, System::EventArgs^ e) {
		switch (mOp)
		{
		case '+':
			mResult = mLhInput + mRhInput;
			break;
		case '-':
			mResult = mLhInput - mRhInput;
			break;
		case '*':
			mResult = mLhInput * mRhInput;
			break;
		case '/':
			mResult = mLhInput / mRhInput;
			break;
		default:
			break;
		}

		String^ temp = mResult.ToString();

		display->Text = temp;

		reset();
	}
	};
}

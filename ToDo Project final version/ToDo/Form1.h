// Start
#include "addsuccess.h" // include add success form to form 1

namespace ToDo {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient; // connect my sql


	// connection struct class
	value struct con_struct{
	static 	String^ constr="Server=127.0.0.1;Uid=root;Pwd=;Database=todo;SslMode=none"; 
	};
		

	// todo struct class
	 value struct todo_struct{
		static   String ^ title ;
		static   int    ^ priority;
		static   String ^ overdue ;
		static   String ^ details;
		static   String ^ statue;
		static   int ^ id;
	};
	

	 // form1 class
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{

			 InitializeComponent();                      // form 1 default
			 FillRemovalCombo();                        //FillTheRemoval ComboBox
			 FilloverdueCombo();                       //Fill overdue combo
			 FilltodoCombo();                         // fill todo today combo box
			 SidePanel->Height = button1->Height;    // main page ->slide panel control
			 SidePanel->Top = button1->Top;         // main page ->slide panel control
			 FillTodolistListView();               // fill listview on todo list panel
			 FillDoneListView();                  // fill done listview on done panel
		///---------------------------------------------------
				//hide and show panels
			panel6->Visible=false;                // remove button panel (hide)
			panel4->Visible = true;              // home button panel (show)
			panel5->Visible=false;              //  add new task button panel (hide)
			panel7->Visible=false;             // edit button panel (hide)
			panel9->Visible=false;            // todo today  button panel (hide)
			panel17->Visible=false;          // overdue button panel (hide)
			panel26->Visible=false;         // search button panel (hide)
			panel29->Visible=false;        // question mark button panel(hide)
			panel35->Visible=false;       // todo lists button panel (show)
			panel45->Visible=false;      // done button panel (hide)
	  ///---------------------------------------------------
		}

	protected:
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

//connection global object (con struct)
		static con_struct^ conobj = gcnew con_struct();

// todo global object (todo struct)
		static todo_struct^ todoobj = gcnew todo_struct();

// counter global variable (used in search task)
		static int x=0;
	
private: System::Windows::Forms::Panel^  panel1;
protected: 
private: System::Windows::Forms::PictureBox^  pictureBox2;
private: System::Windows::Forms::Button^  button8;
private: System::Windows::Forms::Panel^  SidePanel;
private: System::Windows::Forms::Button^  button7;
private: System::Windows::Forms::Button^  button6;
private: System::Windows::Forms::Button^  button5;
private: System::Windows::Forms::Button^  button4;
private: System::Windows::Forms::Button^  button3;
private: System::Windows::Forms::Button^  button14;
private: System::Windows::Forms::Button^  button2;
private: System::Windows::Forms::Button^  button1;
private: System::Windows::Forms::Panel^  panel3;
private: System::Windows::Forms::Label^  label3;
private: System::Windows::Forms::Label^  label2;
private: System::Windows::Forms::PictureBox^  pictureBox1;
private: System::Windows::Forms::Panel^  panel2;
private: System::Windows::Forms::Button^  button10;
private: System::Windows::Forms::Button^  button9;
private: System::Windows::Forms::Button^  button15;
private: System::Windows::Forms::Button^  button13;
private: System::Windows::Forms::Button^  button11;
private: System::Windows::Forms::Panel^  panel4;
private: System::Windows::Forms::Label^  label1;
private: System::Windows::Forms::Label^  label6;
private: System::Windows::Forms::Label^  label5;
private: System::Windows::Forms::Label^  label4;
private: System::Windows::Forms::Label^  label7;
private: System::Windows::Forms::Label^  label8;
private: System::Windows::Forms::PictureBox^  pictureBox3;
private: System::Windows::Forms::Button^  button12;
private: System::Windows::Forms::Panel^  panel5;
private: System::Windows::Forms::DateTimePicker^  dateTimePicker1;
private: System::Windows::Forms::TextBox^  textBox3;
private: System::Windows::Forms::TextBox^  textBox2;
private: System::Windows::Forms::TextBox^  textBox4;
private: System::Windows::Forms::Button^  button16;
private: System::Windows::Forms::PictureBox^  pictureBox8;
private: System::Windows::Forms::PictureBox^  pictureBox6;
private: System::Windows::Forms::PictureBox^  pictureBox5;
private: System::Windows::Forms::PictureBox^  pictureBox7;
private: System::Windows::Forms::Panel^  panel6;
private: System::Windows::Forms::ComboBox^  comboBox1;
private: System::Windows::Forms::Button^  btnRemoveCombo;
private: System::Windows::Forms::TextBox^  textBox1;
private: System::Windows::Forms::Label^  label10;
private: System::Windows::Forms::Label^  label9;
private: System::Windows::Forms::Label^  label11;
private: System::Windows::Forms::Label^  label12;
private: System::Windows::Forms::Panel^  panel7;
private: System::Windows::Forms::ComboBox^  comboBox2;
private: System::Windows::Forms::Button^  button17;
private: System::Windows::Forms::PictureBox^  pictureBox9;
private: System::Windows::Forms::TextBox^  textBox5;
private: System::Windows::Forms::TextBox^  textBox7;
private: System::Windows::Forms::TextBox^  textBox6;
private: System::Windows::Forms::DateTimePicker^  dateTimePicker2;
private: System::Windows::Forms::CheckBox^  checkBox1;
private: System::Windows::Forms::TextBox^  textBox9;
private: System::Windows::Forms::Panel^  panel8;
private: System::Windows::Forms::Panel^  panel9;
private: System::Windows::Forms::Panel^  panel11;
private: System::Windows::Forms::RadioButton^  radioButton2;
private: System::Windows::Forms::RadioButton^  radioButton1;
private: System::Windows::Forms::TextBox^  textBox8;
private: System::Windows::Forms::ComboBox^  comboBox3;
private: System::Windows::Forms::Panel^  panel12;
private: System::Windows::Forms::PictureBox^  pictureBox4;
private: System::Windows::Forms::Label^  label13;
private: System::Windows::Forms::Panel^  panel10;
private: System::Windows::Forms::Panel^  panel15;
private: System::Windows::Forms::Panel^  panel16;
private: System::Windows::Forms::Panel^  panel14;
private: System::Windows::Forms::Panel^  panel13;
private: System::Windows::Forms::ComboBox^  comboBox4;
private: System::Windows::Forms::PictureBox^  pictureBox10;
private: System::Windows::Forms::Panel^  panel18;
private: System::Windows::Forms::Panel^  panel20;
private: System::Windows::Forms::TextBox^  textBox10;
private: System::Windows::Forms::Panel^  panel17;
private: System::Windows::Forms::Panel^  panel19;
private: System::Windows::Forms::Panel^  panel21;
private: System::Windows::Forms::Panel^  panel22;
private: System::Windows::Forms::Panel^  panel23;
private: System::Windows::Forms::Panel^  panel24;
private: System::Windows::Forms::Label^  label14;
private: System::Windows::Forms::Panel^  panel25;
private: System::Windows::Forms::Panel^  panel26;
private: System::Windows::Forms::Panel^  panel28;
private: System::Windows::Forms::Panel^  panel27;
private: System::Windows::Forms::TextBox^  textBox11;
private: System::Windows::Forms::Button^  button18;
private: System::Windows::Forms::DateTimePicker^  dateTimePicker3;
private: System::Windows::Forms::TextBox^  textBox12;
private: System::Windows::Forms::TextBox^  textBox13;
private: System::Windows::Forms::Label^  label19;
private: System::Windows::Forms::RadioButton^  radioButton3;
private: System::Windows::Forms::RadioButton^  radioButton4;
private: System::Windows::Forms::RadioButton^  radioButton5;
private: System::Windows::Forms::ListBox^  listBox1;
private: System::Windows::Forms::TextBox^  textBox14;
private: System::Windows::Forms::RadioButton^  radioButton6;
private: System::Windows::Forms::Panel^  panel29;
private: System::Windows::Forms::Panel^  panel33;
private: System::Windows::Forms::Panel^  panel32;
private: System::Windows::Forms::Panel^  panel31;
private: System::Windows::Forms::Panel^  panel30;
private: System::Windows::Forms::Label^  label17;
private: System::Windows::Forms::Label^  label16;
private: System::Windows::Forms::Label^  label15;
private: System::Windows::Forms::Label^  label28;
private: System::Windows::Forms::Label^  label27;
private: System::Windows::Forms::Label^  label26;
private: System::Windows::Forms::Panel^  panel34;
private: System::Windows::Forms::Label^  label25;
private: System::Windows::Forms::Label^  label24;
private: System::Windows::Forms::Label^  label23;
private: System::Windows::Forms::Label^  label22;
private: System::Windows::Forms::Label^  label21;
private: System::Windows::Forms::Label^  label20;
private: System::Windows::Forms::Label^  label18;
private: System::Windows::Forms::Label^  label30;
private: System::Windows::Forms::Label^  label29;
private: System::Windows::Forms::Panel^  panel35;
private: System::Windows::Forms::Panel^  panel36;
private: System::Windows::Forms::Label^  label32;
private: System::Windows::Forms::Button^  button20;
private: System::Windows::Forms::TextBox^  textBox15;
private: System::Windows::Forms::Label^  label31;
private: System::Windows::Forms::ListView^  listView1;
private: System::Windows::Forms::ColumnHeader^  ID;
private: System::Windows::Forms::ColumnHeader^  Title;
private: System::Windows::Forms::ColumnHeader^  Priority;
private: System::Windows::Forms::ColumnHeader^  Overdue;
private: System::Windows::Forms::ColumnHeader^  Details;
private: System::Windows::Forms::ColumnHeader^  columnHeader1;
private: System::Windows::Forms::Panel^  panel40;
private: System::Windows::Forms::Panel^  panel39;
private: System::Windows::Forms::Panel^  panel38;
private: System::Windows::Forms::Panel^  panel37;
private: System::Windows::Forms::Panel^  panel44;
private: System::Windows::Forms::Panel^  panel43;
private: System::Windows::Forms::Panel^  panel42;
private: System::Windows::Forms::Panel^  panel41;
private: System::Windows::Forms::ListView^  listView2;
private: System::Windows::Forms::ColumnHeader^  iID;
private: System::Windows::Forms::ColumnHeader^  iTitle;
private: System::Windows::Forms::ColumnHeader^  iPriority;
private: System::Windows::Forms::ColumnHeader^  iOverdue;
private: System::Windows::Forms::ColumnHeader^  iDetails;
private: System::Windows::Forms::ColumnHeader^  iState;
private: System::Windows::Forms::Label^  label33;
private: System::Windows::Forms::Panel^  panel46;
private: System::Windows::Forms::Panel^  panel54;
private: System::Windows::Forms::Panel^  panel53;
private: System::Windows::Forms::Panel^  panel52;
private: System::Windows::Forms::Panel^  panel51;
private: System::Windows::Forms::Label^  label34;
private: System::Windows::Forms::Button^  button19;
private: System::Windows::Forms::TextBox^  textBox16;
private: System::Windows::Forms::Panel^  panel47;
private: System::Windows::Forms::Panel^  panel48;
private: System::Windows::Forms::Panel^  panel49;
private: System::Windows::Forms::Panel^  panel50;
private: System::Windows::Forms::Panel^  panel45;
	private:
		System::ComponentModel::Container ^components;

 //Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->SidePanel = (gcnew System::Windows::Forms::Panel());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button14 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button15 = (gcnew System::Windows::Forms::Button());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox7 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox8 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox6 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->button16 = (gcnew System::Windows::Forms::Button());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->btnRemoveCombo = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->dateTimePicker2 = (gcnew System::Windows::Forms::DateTimePicker());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox9 = (gcnew System::Windows::Forms::PictureBox());
			this->button17 = (gcnew System::Windows::Forms::Button());
			this->panel8 = (gcnew System::Windows::Forms::Panel());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->panel9 = (gcnew System::Windows::Forms::Panel());
			this->panel14 = (gcnew System::Windows::Forms::Panel());
			this->panel13 = (gcnew System::Windows::Forms::Panel());
			this->panel16 = (gcnew System::Windows::Forms::Panel());
			this->panel15 = (gcnew System::Windows::Forms::Panel());
			this->panel10 = (gcnew System::Windows::Forms::Panel());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->panel12 = (gcnew System::Windows::Forms::Panel());
			this->panel11 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox4 = (gcnew System::Windows::Forms::ComboBox());
			this->pictureBox10 = (gcnew System::Windows::Forms::PictureBox());
			this->panel18 = (gcnew System::Windows::Forms::Panel());
			this->panel20 = (gcnew System::Windows::Forms::Panel());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->panel17 = (gcnew System::Windows::Forms::Panel());
			this->panel19 = (gcnew System::Windows::Forms::Panel());
			this->panel21 = (gcnew System::Windows::Forms::Panel());
			this->panel22 = (gcnew System::Windows::Forms::Panel());
			this->panel23 = (gcnew System::Windows::Forms::Panel());
			this->panel24 = (gcnew System::Windows::Forms::Panel());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->panel25 = (gcnew System::Windows::Forms::Panel());
			this->panel26 = (gcnew System::Windows::Forms::Panel());
			this->textBox14 = (gcnew System::Windows::Forms::TextBox());
			this->radioButton6 = (gcnew System::Windows::Forms::RadioButton());
			this->panel28 = (gcnew System::Windows::Forms::Panel());
			this->panel27 = (gcnew System::Windows::Forms::Panel());
			this->textBox11 = (gcnew System::Windows::Forms::TextBox());
			this->button18 = (gcnew System::Windows::Forms::Button());
			this->dateTimePicker3 = (gcnew System::Windows::Forms::DateTimePicker());
			this->textBox12 = (gcnew System::Windows::Forms::TextBox());
			this->textBox13 = (gcnew System::Windows::Forms::TextBox());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton5 = (gcnew System::Windows::Forms::RadioButton());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->panel29 = (gcnew System::Windows::Forms::Panel());
			this->label30 = (gcnew System::Windows::Forms::Label());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->panel34 = (gcnew System::Windows::Forms::Panel());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->panel33 = (gcnew System::Windows::Forms::Panel());
			this->panel32 = (gcnew System::Windows::Forms::Panel());
			this->panel31 = (gcnew System::Windows::Forms::Panel());
			this->panel30 = (gcnew System::Windows::Forms::Panel());
			this->panel35 = (gcnew System::Windows::Forms::Panel());
			this->panel44 = (gcnew System::Windows::Forms::Panel());
			this->panel43 = (gcnew System::Windows::Forms::Panel());
			this->panel42 = (gcnew System::Windows::Forms::Panel());
			this->panel41 = (gcnew System::Windows::Forms::Panel());
			this->panel36 = (gcnew System::Windows::Forms::Panel());
			this->panel40 = (gcnew System::Windows::Forms::Panel());
			this->panel39 = (gcnew System::Windows::Forms::Panel());
			this->panel38 = (gcnew System::Windows::Forms::Panel());
			this->panel37 = (gcnew System::Windows::Forms::Panel());
			this->label32 = (gcnew System::Windows::Forms::Label());
			this->button20 = (gcnew System::Windows::Forms::Button());
			this->textBox15 = (gcnew System::Windows::Forms::TextBox());
			this->label31 = (gcnew System::Windows::Forms::Label());
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->ID = (gcnew System::Windows::Forms::ColumnHeader());
			this->Title = (gcnew System::Windows::Forms::ColumnHeader());
			this->Priority = (gcnew System::Windows::Forms::ColumnHeader());
			this->Overdue = (gcnew System::Windows::Forms::ColumnHeader());
			this->Details = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader1 = (gcnew System::Windows::Forms::ColumnHeader());
			this->listView2 = (gcnew System::Windows::Forms::ListView());
			this->iID = (gcnew System::Windows::Forms::ColumnHeader());
			this->iTitle = (gcnew System::Windows::Forms::ColumnHeader());
			this->iPriority = (gcnew System::Windows::Forms::ColumnHeader());
			this->iOverdue = (gcnew System::Windows::Forms::ColumnHeader());
			this->iDetails = (gcnew System::Windows::Forms::ColumnHeader());
			this->iState = (gcnew System::Windows::Forms::ColumnHeader());
			this->label33 = (gcnew System::Windows::Forms::Label());
			this->panel46 = (gcnew System::Windows::Forms::Panel());
			this->panel54 = (gcnew System::Windows::Forms::Panel());
			this->panel53 = (gcnew System::Windows::Forms::Panel());
			this->panel52 = (gcnew System::Windows::Forms::Panel());
			this->panel51 = (gcnew System::Windows::Forms::Panel());
			this->label34 = (gcnew System::Windows::Forms::Label());
			this->button19 = (gcnew System::Windows::Forms::Button());
			this->textBox16 = (gcnew System::Windows::Forms::TextBox());
			this->panel47 = (gcnew System::Windows::Forms::Panel());
			this->panel48 = (gcnew System::Windows::Forms::Panel());
			this->panel49 = (gcnew System::Windows::Forms::Panel());
			this->panel50 = (gcnew System::Windows::Forms::Panel());
			this->panel45 = (gcnew System::Windows::Forms::Panel());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox2))->BeginInit();
			this->panel3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->panel4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox3))->BeginInit();
			this->panel5->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox8))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox5))->BeginInit();
			this->panel6->SuspendLayout();
			this->panel7->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox9))->BeginInit();
			this->panel9->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox10))->BeginInit();
			this->panel17->SuspendLayout();
			this->panel26->SuspendLayout();
			this->panel29->SuspendLayout();
			this->panel35->SuspendLayout();
			this->panel36->SuspendLayout();
			this->panel46->SuspendLayout();
			this->panel45->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)), static_cast<System::Int32>(static_cast<System::Byte>(39)), 
				static_cast<System::Int32>(static_cast<System::Byte>(40)));
			this->panel1->Controls->Add(this->pictureBox2);
			this->panel1->Controls->Add(this->button8);
			this->panel1->Controls->Add(this->SidePanel);
			this->panel1->Controls->Add(this->button7);
			this->panel1->Controls->Add(this->button6);
			this->panel1->Controls->Add(this->button5);
			this->panel1->Controls->Add(this->button4);
			this->panel1->Controls->Add(this->button3);
			this->panel1->Controls->Add(this->button14);
			this->panel1->Controls->Add(this->button2);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Margin = System::Windows::Forms::Padding(4);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(279, 670);
			this->panel1->TabIndex = 3;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(0, 4);
			this->pictureBox2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(71, 60);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox2->TabIndex = 27;
			this->pictureBox2->TabStop = false;
			// 
			// button8
			// 
			this->button8->FlatAppearance->BorderSize = 0;
			this->button8->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button8->Font = (gcnew System::Drawing::Font(L"Century Gothic", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button8->ForeColor = System::Drawing::Color::White;
			this->button8->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"button8.Image")));
			this->button8->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button8->Location = System::Drawing::Point(16, 535);
			this->button8->Margin = System::Windows::Forms::Padding(4);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(263, 66);
			this->button8->TabIndex = 5;
			this->button8->Text = L"       Search";
			this->button8->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &Form1::button8_Click);
			// 
			// SidePanel
			// 
			this->SidePanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(178)), static_cast<System::Int32>(static_cast<System::Byte>(8)), 
				static_cast<System::Int32>(static_cast<System::Byte>(55)));
			this->SidePanel->Location = System::Drawing::Point(1, 75);
			this->SidePanel->Margin = System::Windows::Forms::Padding(4);
			this->SidePanel->Name = L"SidePanel";
			this->SidePanel->Size = System::Drawing::Size(13, 66);
			this->SidePanel->TabIndex = 4;
			// 
			// button7
			// 
			this->button7->FlatAppearance->BorderSize = 0;
			this->button7->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button7->Font = (gcnew System::Drawing::Font(L"Century Gothic", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button7->ForeColor = System::Drawing::Color::White;
			this->button7->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"button7.Image")));
			this->button7->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button7->Location = System::Drawing::Point(16, 471);
			this->button7->Margin = System::Windows::Forms::Padding(4);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(263, 66);
			this->button7->TabIndex = 4;
			this->button7->Text = L"       Remove";
			this->button7->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &Form1::button7_Click);
			// 
			// button6
			// 
			this->button6->FlatAppearance->BorderSize = 0;
			this->button6->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button6->Font = (gcnew System::Drawing::Font(L"Century Gothic", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button6->ForeColor = System::Drawing::Color::White;
			this->button6->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"button6.Image")));
			this->button6->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button6->Location = System::Drawing::Point(16, 405);
			this->button6->Margin = System::Windows::Forms::Padding(4);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(263, 66);
			this->button6->TabIndex = 4;
			this->button6->Text = L"       Edit";
			this->button6->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Form1::button6_Click);
			// 
			// button5
			// 
			this->button5->FlatAppearance->BorderSize = 0;
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button5->Font = (gcnew System::Drawing::Font(L"Century Gothic", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button5->ForeColor = System::Drawing::Color::White;
			this->button5->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"button5.Image")));
			this->button5->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button5->Location = System::Drawing::Point(16, 338);
			this->button5->Margin = System::Windows::Forms::Padding(4);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(263, 66);
			this->button5->TabIndex = 4;
			this->button5->Text = L"       Overdue";
			this->button5->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
			// 
			// button4
			// 
			this->button4->FlatAppearance->BorderSize = 0;
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button4->Font = (gcnew System::Drawing::Font(L"Century Gothic", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button4->ForeColor = System::Drawing::Color::White;
			this->button4->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"button4.Image")));
			this->button4->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button4->Location = System::Drawing::Point(16, 272);
			this->button4->Margin = System::Windows::Forms::Padding(4);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(263, 66);
			this->button4->TabIndex = 4;
			this->button4->Text = L"       Done";
			this->button4->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// button3
			// 
			this->button3->FlatAppearance->BorderSize = 0;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Font = (gcnew System::Drawing::Font(L"Century Gothic", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button3->ForeColor = System::Drawing::Color::White;
			this->button3->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"button3.Image")));
			this->button3->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button3->Location = System::Drawing::Point(16, 139);
			this->button3->Margin = System::Windows::Forms::Padding(4);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(263, 66);
			this->button3->TabIndex = 4;
			this->button3->Text = L"       ToDo Lists";
			this->button3->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// button14
			// 
			this->button14->FlatAppearance->BorderSize = 0;
			this->button14->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button14->Font = (gcnew System::Drawing::Font(L"Century Gothic", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button14->ForeColor = System::Drawing::Color::White;
			this->button14->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button14->Location = System::Drawing::Point(16, 624);
			this->button14->Margin = System::Windows::Forms::Padding(4);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(48, 42);
			this->button14->TabIndex = 4;
			this->button14->Text = L"\?";
			this->button14->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button14->UseVisualStyleBackColor = true;
			this->button14->Click += gcnew System::EventHandler(this, &Form1::button14_Click);
			// 
			// button2
			// 
			this->button2->FlatAppearance->BorderSize = 0;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Century Gothic", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::Color::White;
			this->button2->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"button2.Image")));
			this->button2->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button2->Location = System::Drawing::Point(16, 206);
			this->button2->Margin = System::Windows::Forms::Padding(4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(263, 66);
			this->button2->TabIndex = 4;
			this->button2->Text = L"       ToDo Today";
			this->button2->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button1
			// 
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Century Gothic", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::White;
			this->button1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"button1.Image")));
			this->button1->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button1->Location = System::Drawing::Point(16, 73);
			this->button1->Margin = System::Windows::Forms::Padding(4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(263, 66);
			this->button1->TabIndex = 4;
			this->button1->Text = L"       Home";
			this->button1->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(178)), static_cast<System::Int32>(static_cast<System::Byte>(8)), 
				static_cast<System::Int32>(static_cast<System::Byte>(55)));
			this->panel3->Controls->Add(this->label3);
			this->panel3->Controls->Add(this->label2);
			this->panel3->Controls->Add(this->pictureBox1);
			this->panel3->Location = System::Drawing::Point(324, 0);
			this->panel3->Margin = System::Windows::Forms::Padding(4);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(148, 176);
			this->panel3->TabIndex = 19;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Century Gothic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->Location = System::Drawing::Point(19, 142);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(51, 20);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Saver";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(19, 118);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(93, 23);
			this->label2->TabIndex = 3;
			this->label2->Text = L"ToDo List";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(23, 20);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(4);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(108, 92);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 4;
			this->pictureBox1->TabStop = false;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(178)), static_cast<System::Int32>(static_cast<System::Byte>(8)), 
				static_cast<System::Int32>(static_cast<System::Byte>(55)));
			this->panel2->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel2->Location = System::Drawing::Point(279, 0);
			this->panel2->Margin = System::Windows::Forms::Padding(4);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1044, 12);
			this->panel2->TabIndex = 20;
			// 
			// button10
			// 
			this->button10->FlatAppearance->BorderSize = 0;
			this->button10->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button10->Font = (gcnew System::Drawing::Font(L"Century Gothic", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button10->ForeColor = System::Drawing::Color::White;
			this->button10->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"button10.Image")));
			this->button10->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button10->Location = System::Drawing::Point(1024, 22);
			this->button10->Margin = System::Windows::Forms::Padding(4);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(48, 42);
			this->button10->TabIndex = 23;
			this->button10->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button10->UseVisualStyleBackColor = true;
			// 
			// button9
			// 
			this->button9->FlatAppearance->BorderSize = 0;
			this->button9->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button9->Font = (gcnew System::Drawing::Font(L"Century Gothic", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button9->ForeColor = System::Drawing::Color::White;
			this->button9->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"button9.Image")));
			this->button9->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button9->Location = System::Drawing::Point(968, 22);
			this->button9->Margin = System::Windows::Forms::Padding(4);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(48, 42);
			this->button9->TabIndex = 22;
			this->button9->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button9->UseVisualStyleBackColor = true;
			// 
			// button15
			// 
			this->button15->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button15->FlatAppearance->BorderSize = 0;
			this->button15->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button15->Font = (gcnew System::Drawing::Font(L"Century Gothic", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button15->ForeColor = System::Drawing::Color::White;
			this->button15->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"button15.Image")));
			this->button15->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button15->Location = System::Drawing::Point(912, 22);
			this->button15->Margin = System::Windows::Forms::Padding(4);
			this->button15->Name = L"button15";
			this->button15->Size = System::Drawing::Size(48, 42);
			this->button15->TabIndex = 21;
			this->button15->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button15->UseVisualStyleBackColor = true;
			// 
			// button13
			// 
			this->button13->FlatAppearance->BorderSize = 0;
			this->button13->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button13->Font = (gcnew System::Drawing::Font(L"Century Gothic", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button13->ForeColor = System::Drawing::Color::White;
			this->button13->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"button13.Image")));
			this->button13->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button13->Location = System::Drawing::Point(1267, 22);
			this->button13->Margin = System::Windows::Forms::Padding(4);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(43, 43);
			this->button13->TabIndex = 25;
			this->button13->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button13->UseVisualStyleBackColor = true;
			this->button13->Click += gcnew System::EventHandler(this, &Form1::button13_Click);
			// 
			// button11
			// 
			this->button11->FlatAppearance->BorderSize = 0;
			this->button11->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button11->Font = (gcnew System::Drawing::Font(L"Century Gothic", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button11->ForeColor = System::Drawing::Color::White;
			this->button11->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"button11.Image")));
			this->button11->Location = System::Drawing::Point(1225, 25);
			this->button11->Margin = System::Windows::Forms::Padding(4);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(23, 37);
			this->button11->TabIndex = 26;
			this->button11->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Click += gcnew System::EventHandler(this, &Form1::button11_Click_1);
			// 
			// panel4
			// 
			this->panel4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"panel4.BackgroundImage")));
			this->panel4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel4->Controls->Add(this->button12);
			this->panel4->Controls->Add(this->pictureBox3);
			this->panel4->Controls->Add(this->label6);
			this->panel4->Controls->Add(this->label5);
			this->panel4->Controls->Add(this->label4);
			this->panel4->Controls->Add(this->label7);
			this->panel4->Controls->Add(this->label8);
			this->panel4->Controls->Add(this->label1);
			this->panel4->Location = System::Drawing::Point(279, 183);
			this->panel4->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(1109, 487);
			this->panel4->TabIndex = 27;
			this->panel4->Visible = false;
			// 
			// button12
			// 
			this->button12->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->button12->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->button12->FlatAppearance->BorderSize = 0;
			this->button12->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->button12->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->button12->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button12->ForeColor = System::Drawing::Color::White;
			this->button12->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"button12.Image")));
			this->button12->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button12->Location = System::Drawing::Point(357, 394);
			this->button12->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(313, 42);
			this->button12->TabIndex = 32;
			this->button12->Text = L"    Add New Task";
			this->button12->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->button12->UseVisualStyleBackColor = false;
			this->button12->Click += gcnew System::EventHandler(this, &Form1::button12_Click);
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackColor = System::Drawing::Color::White;
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(299, 142);
			this->pictureBox3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(427, 303);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox3->TabIndex = 31;
			this->pictureBox3->TabStop = false;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Century Gothic", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::DimGray;
			this->label6->Location = System::Drawing::Point(832, 92);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(33, 49);
			this->label6->TabIndex = 30;
			this->label6->Text = L".";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Century Gothic", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::Red;
			this->label5->Location = System::Drawing::Point(687, 92);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(155, 49);
			this->label5->TabIndex = 29;
			this->label5->Text = L"\'Never\'";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Century Gothic", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::DimGray;
			this->label4->Location = System::Drawing::Point(477, 92);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(204, 49);
			this->label4->TabIndex = 28;
			this->label4->Text = L"Becomes";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Century Gothic", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::Color::Red;
			this->label7->Location = System::Drawing::Point(336, 92);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(135, 49);
			this->label7->TabIndex = 27;
			this->label7->Text = L"\'Later\'";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Century Gothic", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label8->ForeColor = System::Drawing::Color::DimGray;
			this->label8->Location = System::Drawing::Point(83, 92);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(248, 49);
			this->label8->TabIndex = 26;
			this->label8->Text = L"Some times";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Century Gothic", 48, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(283, -18);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(455, 93);
			this->label1->TabIndex = 25;
			this->label1->Text = L"Do It Now !";
			// 
			// panel5
			// 
			this->panel5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"panel5.BackgroundImage")));
			this->panel5->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel5->Controls->Add(this->pictureBox7);
			this->panel5->Controls->Add(this->pictureBox8);
			this->panel5->Controls->Add(this->pictureBox6);
			this->panel5->Controls->Add(this->pictureBox5);
			this->panel5->Controls->Add(this->button16);
			this->panel5->Controls->Add(this->textBox4);
			this->panel5->Controls->Add(this->dateTimePicker1);
			this->panel5->Controls->Add(this->textBox3);
			this->panel5->Controls->Add(this->textBox2);
			this->panel5->Location = System::Drawing::Point(279, 183);
			this->panel5->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(1043, 487);
			this->panel5->TabIndex = 28;
			// 
			// pictureBox7
			// 
			this->pictureBox7->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox7.Image")));
			this->pictureBox7->Location = System::Drawing::Point(477, 209);
			this->pictureBox7->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox7->Name = L"pictureBox7";
			this->pictureBox7->Size = System::Drawing::Size(32, 32);
			this->pictureBox7->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox7->TabIndex = 16;
			this->pictureBox7->TabStop = false;
			this->pictureBox7->Click += gcnew System::EventHandler(this, &Form1::pictureBox7_Click);
			// 
			// pictureBox8
			// 
			this->pictureBox8->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox8.Image")));
			this->pictureBox8->Location = System::Drawing::Point(645, 382);
			this->pictureBox8->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox8->Name = L"pictureBox8";
			this->pictureBox8->Size = System::Drawing::Size(32, 32);
			this->pictureBox8->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox8->TabIndex = 15;
			this->pictureBox8->TabStop = false;
			this->pictureBox8->Click += gcnew System::EventHandler(this, &Form1::pictureBox8_Click);
			// 
			// pictureBox6
			// 
			this->pictureBox6->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox6.Image")));
			this->pictureBox6->Location = System::Drawing::Point(377, 123);
			this->pictureBox6->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox6->Name = L"pictureBox6";
			this->pictureBox6->Size = System::Drawing::Size(32, 32);
			this->pictureBox6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox6->TabIndex = 13;
			this->pictureBox6->TabStop = false;
			this->pictureBox6->Click += gcnew System::EventHandler(this, &Form1::pictureBox6_Click);
			// 
			// pictureBox5
			// 
			this->pictureBox5->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox5.Image")));
			this->pictureBox5->Location = System::Drawing::Point(516, 43);
			this->pictureBox5->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(32, 32);
			this->pictureBox5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox5->TabIndex = 12;
			this->pictureBox5->TabStop = false;
			this->pictureBox5->Click += gcnew System::EventHandler(this, &Form1::pictureBox5_Click);
			// 
			// button16
			// 
			this->button16->BackColor = System::Drawing::SystemColors::Control;
			this->button16->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"button16.BackgroundImage")));
			this->button16->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button16->FlatAppearance->BorderSize = 0;
			this->button16->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button16->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)), 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button16->ForeColor = System::Drawing::Color::Brown;
			this->button16->Location = System::Drawing::Point(731, 2);
			this->button16->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button16->Name = L"button16";
			this->button16->Size = System::Drawing::Size(209, 160);
			this->button16->TabIndex = 9;
			this->button16->Text = L"ADD";
			this->button16->TextAlign = System::Drawing::ContentAlignment::BottomRight;
			this->button16->UseVisualStyleBackColor = false;
			this->button16->Click += gcnew System::EventHandler(this, &Form1::button16_Click);
			// 
			// textBox4
			// 
			this->textBox4->BackColor = System::Drawing::SystemColors::Control;
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox4->ForeColor = System::Drawing::Color::Brown;
			this->textBox4->Location = System::Drawing::Point(181, 103);
			this->textBox4->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(135, 45);
			this->textBox4->TabIndex = 5;
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->CalendarForeColor = System::Drawing::Color::Brown;
			this->dateTimePicker1->CalendarMonthBackground = System::Drawing::SystemColors::Control;
			this->dateTimePicker1->CalendarTitleForeColor = System::Drawing::Color::Brown;
			this->dateTimePicker1->CustomFormat = L"yyyy-MM-dd";
			this->dateTimePicker1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->dateTimePicker1->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dateTimePicker1->Location = System::Drawing::Point(281, 209);
			this->dateTimePicker1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(171, 30);
			this->dateTimePicker1->TabIndex = 3;
			this->dateTimePicker1->Value = System::DateTime(2018, 4, 5, 8, 52, 29, 0);
			// 
			// textBox3
			// 
			this->textBox3->BackColor = System::Drawing::SystemColors::Control;
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox3->ForeColor = System::Drawing::Color::Brown;
			this->textBox3->Location = System::Drawing::Point(181, 288);
			this->textBox3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox3->Multiline = true;
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(457, 125);
			this->textBox3->TabIndex = 2;
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::SystemColors::Control;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox2->ForeColor = System::Drawing::Color::Brown;
			this->textBox2->Location = System::Drawing::Point(181, 23);
			this->textBox2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(329, 52);
			this->textBox2->TabIndex = 1;
			// 
			// panel6
			// 
			this->panel6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"panel6.BackgroundImage")));
			this->panel6->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel6->Controls->Add(this->label11);
			this->panel6->Controls->Add(this->label12);
			this->panel6->Controls->Add(this->label10);
			this->panel6->Controls->Add(this->label9);
			this->panel6->Controls->Add(this->textBox1);
			this->panel6->Controls->Add(this->btnRemoveCombo);
			this->panel6->Controls->Add(this->comboBox1);
			this->panel6->Location = System::Drawing::Point(279, 183);
			this->panel6->Margin = System::Windows::Forms::Padding(4);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(1045, 487);
			this->panel6->TabIndex = 29;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Century Gothic", 25.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label11->ForeColor = System::Drawing::Color::Gray;
			this->label11->Location = System::Drawing::Point(1019, 112);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(34, 52);
			this->label11->TabIndex = 37;
			this->label11->Text = L".";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Century Gothic", 25.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label12->ForeColor = System::Drawing::Color::Firebrick;
			this->label12->Location = System::Drawing::Point(936, 112);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(91, 52);
			this->label12->TabIndex = 36;
			this->label12->Text = L"Fail";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Century Gothic", 25.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label10->ForeColor = System::Drawing::Color::Gray;
			this->label10->Location = System::Drawing::Point(543, 57);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(431, 52);
			this->label10->TabIndex = 34;
			this->label10->Text = L"to plan is palning to";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Century Gothic", 25.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label9->ForeColor = System::Drawing::Color::Firebrick;
			this->label9->Location = System::Drawing::Point(467, 2);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(155, 52);
			this->label9->TabIndex = 33;
			this->label9->Text = L"Failing";
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::SystemColors::Control;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->textBox1->Location = System::Drawing::Point(20, 123);
			this->textBox1->Margin = System::Windows::Forms::Padding(4);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->textBox1->Size = System::Drawing::Size(432, 333);
			this->textBox1->TabIndex = 0;
			// 
			// btnRemoveCombo
			// 
			this->btnRemoveCombo->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(178)), static_cast<System::Int32>(static_cast<System::Byte>(8)), 
				static_cast<System::Int32>(static_cast<System::Byte>(55)));
			this->btnRemoveCombo->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnRemoveCombo->FlatAppearance->BorderSize = 0;
			this->btnRemoveCombo->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnRemoveCombo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold));
			this->btnRemoveCombo->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->btnRemoveCombo->Location = System::Drawing::Point(486, 359);
			this->btnRemoveCombo->Margin = System::Windows::Forms::Padding(4);
			this->btnRemoveCombo->Name = L"btnRemoveCombo";
			this->btnRemoveCombo->Size = System::Drawing::Size(159, 97);
			this->btnRemoveCombo->TabIndex = 32;
			this->btnRemoveCombo->Text = L"Delete";
			this->btnRemoveCombo->UseVisualStyleBackColor = false;
			this->btnRemoveCombo->Click += gcnew System::EventHandler(this, &Form1::btnRemoveCombo_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(178)), static_cast<System::Int32>(static_cast<System::Byte>(8)), 
				static_cast<System::Int32>(static_cast<System::Byte>(55)));
			this->comboBox1->DropDownWidth = 300;
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"Century Gothic", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->comboBox1->ForeColor = System::Drawing::Color::White;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(20, 54);
			this->comboBox1->Margin = System::Windows::Forms::Padding(4);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(432, 35);
			this->comboBox1->TabIndex = 30;
			this->comboBox1->Text = L"                   Select The Task";
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBox1_SelectedIndexChanged);
			// 
			// panel7
			// 
			this->panel7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"panel7.BackgroundImage")));
			this->panel7->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel7->Controls->Add(this->textBox9);
			this->panel7->Controls->Add(this->checkBox1);
			this->panel7->Controls->Add(this->dateTimePicker2);
			this->panel7->Controls->Add(this->textBox7);
			this->panel7->Controls->Add(this->textBox6);
			this->panel7->Controls->Add(this->textBox5);
			this->panel7->Controls->Add(this->pictureBox9);
			this->panel7->Controls->Add(this->button17);
			this->panel7->Controls->Add(this->panel8);
			this->panel7->Controls->Add(this->comboBox2);
			this->panel7->Location = System::Drawing::Point(279, 183);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(1044, 487);
			this->panel7->TabIndex = 30;
			// 
			// textBox9
			// 
			this->textBox9->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(240)), 
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->textBox9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox9->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->textBox9->Location = System::Drawing::Point(168, 311);
			this->textBox9->Multiline = true;
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(400, 124);
			this->textBox9->TabIndex = 26;
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->checkBox1->ForeColor = System::Drawing::Color::DimGray;
			this->checkBox1->Location = System::Drawing::Point(168, 441);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(103, 33);
			this->checkBox1->TabIndex = 25;
			this->checkBox1->Text = L"Statue";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox1_CheckedChanged);
			// 
			// dateTimePicker2
			// 
			this->dateTimePicker2->CalendarForeColor = System::Drawing::SystemColors::WindowFrame;
			this->dateTimePicker2->CalendarTitleForeColor = System::Drawing::SystemColors::WindowFrame;
			this->dateTimePicker2->CustomFormat = L"yyyy-MM-dd";
			this->dateTimePicker2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->dateTimePicker2->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dateTimePicker2->Location = System::Drawing::Point(266, 264);
			this->dateTimePicker2->Name = L"dateTimePicker2";
			this->dateTimePicker2->Size = System::Drawing::Size(172, 30);
			this->dateTimePicker2->TabIndex = 24;
			// 
			// textBox7
			// 
			this->textBox7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(240)), 
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->textBox7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox7->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->textBox7->Location = System::Drawing::Point(181, 201);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(139, 38);
			this->textBox7->TabIndex = 20;
			// 
			// textBox6
			// 
			this->textBox6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(240)), 
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->textBox6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox6->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->textBox6->Location = System::Drawing::Point(181, 144);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(337, 38);
			this->textBox6->TabIndex = 19;
			// 
			// textBox5
			// 
			this->textBox5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(240)), 
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->textBox5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox5->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->textBox5->Location = System::Drawing::Point(181, 89);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(232, 38);
			this->textBox5->TabIndex = 18;
			// 
			// pictureBox9
			// 
			this->pictureBox9->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox9.Image")));
			this->pictureBox9->Location = System::Drawing::Point(406, 33);
			this->pictureBox9->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox9->Name = L"pictureBox9";
			this->pictureBox9->Size = System::Drawing::Size(32, 28);
			this->pictureBox9->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox9->TabIndex = 17;
			this->pictureBox9->TabStop = false;
			// 
			// button17
			// 
			this->button17->BackColor = System::Drawing::Color::MediumOrchid;
			this->button17->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button17->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button17->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button17->Location = System::Drawing::Point(603, 418);
			this->button17->Name = L"button17";
			this->button17->Size = System::Drawing::Size(149, 54);
			this->button17->TabIndex = 9;
			this->button17->Text = L"Edit";
			this->button17->UseVisualStyleBackColor = false;
			this->button17->Click += gcnew System::EventHandler(this, &Form1::button17_Click);
			// 
			// panel8
			// 
			this->panel8->BackColor = System::Drawing::Color::DarkOrchid;
			this->panel8->Location = System::Drawing::Point(-1, 0);
			this->panel8->Name = L"panel8";
			this->panel8->Size = System::Drawing::Size(1044, 10);
			this->panel8->TabIndex = 8;
			// 
			// comboBox2
			// 
			this->comboBox2->DropDownWidth = 250;
			this->comboBox2->Font = (gcnew System::Drawing::Font(L"Century Gothic", 13.8F));
			this->comboBox2->ForeColor = System::Drawing::Color::DarkOrchid;
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Location = System::Drawing::Point(20, 26);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(380, 35);
			this->comboBox2->TabIndex = 0;
			this->comboBox2->Text = L"                    Select Task";
			this->comboBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBox2_SelectedIndexChanged);
			// 
			// panel9
			// 
			this->panel9->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"panel9.BackgroundImage")));
			this->panel9->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel9->Controls->Add(this->panel14);
			this->panel9->Controls->Add(this->panel13);
			this->panel9->Controls->Add(this->panel16);
			this->panel9->Controls->Add(this->panel15);
			this->panel9->Controls->Add(this->panel10);
			this->panel9->Controls->Add(this->label13);
			this->panel9->Controls->Add(this->panel12);
			this->panel9->Controls->Add(this->panel11);
			this->panel9->Controls->Add(this->pictureBox4);
			this->panel9->Controls->Add(this->radioButton2);
			this->panel9->Controls->Add(this->radioButton1);
			this->panel9->Controls->Add(this->textBox8);
			this->panel9->Controls->Add(this->comboBox3);
			this->panel9->Location = System::Drawing::Point(278, 183);
			this->panel9->Name = L"panel9";
			this->panel9->Size = System::Drawing::Size(1046, 487);
			this->panel9->TabIndex = 31;
			// 
			// panel14
			// 
			this->panel14->BackColor = System::Drawing::Color::Maroon;
			this->panel14->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel14->Location = System::Drawing::Point(697, 152);
			this->panel14->Name = L"panel14";
			this->panel14->Size = System::Drawing::Size(10, 22);
			this->panel14->TabIndex = 16;
			// 
			// panel13
			// 
			this->panel13->BackColor = System::Drawing::Color::Maroon;
			this->panel13->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel13->Location = System::Drawing::Point(901, 152);
			this->panel13->Name = L"panel13";
			this->panel13->Size = System::Drawing::Size(10, 22);
			this->panel13->TabIndex = 15;
			// 
			// panel16
			// 
			this->panel16->BackColor = System::Drawing::Color::Maroon;
			this->panel16->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel16->Location = System::Drawing::Point(901, 222);
			this->panel16->Name = L"panel16";
			this->panel16->Size = System::Drawing::Size(10, 22);
			this->panel16->TabIndex = 14;
			// 
			// panel15
			// 
			this->panel15->BackColor = System::Drawing::Color::Maroon;
			this->panel15->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel15->Location = System::Drawing::Point(699, 222);
			this->panel15->Name = L"panel15";
			this->panel15->Size = System::Drawing::Size(10, 22);
			this->panel15->TabIndex = 13;
			// 
			// panel10
			// 
			this->panel10->BackColor = System::Drawing::Color::Maroon;
			this->panel10->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel10->Location = System::Drawing::Point(700, 234);
			this->panel10->Name = L"panel10";
			this->panel10->Size = System::Drawing::Size(208, 10);
			this->panel10->TabIndex = 12;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->label13->Font = (gcnew System::Drawing::Font(L"Century Gothic", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label13->Location = System::Drawing::Point(683, 179);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(257, 40);
			this->label13->TabIndex = 11;
			this->label13->Text = L"yyyy / MM / dd";
			// 
			// panel12
			// 
			this->panel12->BackColor = System::Drawing::Color::Maroon;
			this->panel12->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel12->Location = System::Drawing::Point(697, 152);
			this->panel12->Name = L"panel12";
			this->panel12->Size = System::Drawing::Size(207, 10);
			this->panel12->TabIndex = 8;
			// 
			// panel11
			// 
			this->panel11->BackColor = System::Drawing::Color::Maroon;
			this->panel11->Location = System::Drawing::Point(-1, 0);
			this->panel11->Name = L"panel11";
			this->panel11->Size = System::Drawing::Size(1047, 10);
			this->panel11->TabIndex = 6;
			// 
			// pictureBox4
			// 
			this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox4.Image")));
			this->pictureBox4->Location = System::Drawing::Point(393, 3);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(246, 115);
			this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox4->TabIndex = 5;
			this->pictureBox4->TabStop = false;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->radioButton2->ForeColor = System::Drawing::Color::Red;
			this->radioButton2->Location = System::Drawing::Point(690, 380);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(159, 36);
			this->radioButton2->TabIndex = 3;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"Not done";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->radioButton1->ForeColor = System::Drawing::Color::Green;
			this->radioButton1->Location = System::Drawing::Point(690, 330);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(108, 36);
			this->radioButton1->TabIndex = 2;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Done";
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton1_CheckedChanged);
			// 
			// textBox8
			// 
			this->textBox8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F));
			this->textBox8->Location = System::Drawing::Point(139, 163);
			this->textBox8->Multiline = true;
			this->textBox8->Name = L"textBox8";
			this->textBox8->ReadOnly = true;
			this->textBox8->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->textBox8->Size = System::Drawing::Size(459, 320);
			this->textBox8->TabIndex = 1;
			// 
			// comboBox3
			// 
			this->comboBox3->BackColor = System::Drawing::Color::Maroon;
			this->comboBox3->DropDownWidth = 250;
			this->comboBox3->Font = (gcnew System::Drawing::Font(L"Century Gothic", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->comboBox3->ForeColor = System::Drawing::SystemColors::Menu;
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Location = System::Drawing::Point(139, 122);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(459, 35);
			this->comboBox3->TabIndex = 0;
			this->comboBox3->Text = L"                     Tasks ToDo Today";
			this->comboBox3->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBox3_SelectedIndexChanged);
			// 
			// comboBox4
			// 
			this->comboBox4->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->comboBox4->ForeColor = System::Drawing::Color::Green;
			this->comboBox4->FormattingEnabled = true;
			this->comboBox4->Location = System::Drawing::Point(102, 125);
			this->comboBox4->Name = L"comboBox4";
			this->comboBox4->Size = System::Drawing::Size(448, 31);
			this->comboBox4->TabIndex = 0;
			this->comboBox4->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBox4_SelectedIndexChanged);
			// 
			// pictureBox10
			// 
			this->pictureBox10->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox10.Image")));
			this->pictureBox10->Location = System::Drawing::Point(421, 0);
			this->pictureBox10->Name = L"pictureBox10";
			this->pictureBox10->Size = System::Drawing::Size(166, 116);
			this->pictureBox10->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox10->TabIndex = 1;
			this->pictureBox10->TabStop = false;
			// 
			// panel18
			// 
			this->panel18->BackColor = System::Drawing::Color::DarkSeaGreen;
			this->panel18->ForeColor = System::Drawing::Color::LawnGreen;
			this->panel18->Location = System::Drawing::Point(0, 0);
			this->panel18->Name = L"panel18";
			this->panel18->Size = System::Drawing::Size(1047, 10);
			this->panel18->TabIndex = 2;
			// 
			// panel20
			// 
			this->panel20->BackColor = System::Drawing::Color::DarkSeaGreen;
			this->panel20->ForeColor = System::Drawing::Color::LawnGreen;
			this->panel20->Location = System::Drawing::Point(0, 477);
			this->panel20->Name = L"panel20";
			this->panel20->Size = System::Drawing::Size(1049, 10);
			this->panel20->TabIndex = 33;
			// 
			// textBox10
			// 
			this->textBox10->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(240)), 
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->textBox10->Font = (gcnew System::Drawing::Font(L"Century Gothic", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox10->Location = System::Drawing::Point(47, 168);
			this->textBox10->Multiline = true;
			this->textBox10->Name = L"textBox10";
			this->textBox10->ReadOnly = true;
			this->textBox10->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->textBox10->Size = System::Drawing::Size(552, 303);
			this->textBox10->TabIndex = 34;
			// 
			// panel17
			// 
			this->panel17->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"panel17.BackgroundImage")));
			this->panel17->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel17->Controls->Add(this->panel19);
			this->panel17->Controls->Add(this->panel21);
			this->panel17->Controls->Add(this->panel22);
			this->panel17->Controls->Add(this->panel23);
			this->panel17->Controls->Add(this->panel24);
			this->panel17->Controls->Add(this->label14);
			this->panel17->Controls->Add(this->panel25);
			this->panel17->Controls->Add(this->textBox10);
			this->panel17->Controls->Add(this->panel20);
			this->panel17->Controls->Add(this->panel18);
			this->panel17->Controls->Add(this->pictureBox10);
			this->panel17->Controls->Add(this->comboBox4);
			this->panel17->Location = System::Drawing::Point(277, 183);
			this->panel17->Name = L"panel17";
			this->panel17->Size = System::Drawing::Size(1047, 487);
			this->panel17->TabIndex = 32;
			// 
			// panel19
			// 
			this->panel19->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->panel19->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel19->Location = System::Drawing::Point(691, 43);
			this->panel19->Name = L"panel19";
			this->panel19->Size = System::Drawing::Size(10, 22);
			this->panel19->TabIndex = 41;
			// 
			// panel21
			// 
			this->panel21->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->panel21->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel21->Location = System::Drawing::Point(895, 43);
			this->panel21->Name = L"panel21";
			this->panel21->Size = System::Drawing::Size(10, 22);
			this->panel21->TabIndex = 40;
			// 
			// panel22
			// 
			this->panel22->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->panel22->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel22->Location = System::Drawing::Point(895, 113);
			this->panel22->Name = L"panel22";
			this->panel22->Size = System::Drawing::Size(10, 22);
			this->panel22->TabIndex = 39;
			// 
			// panel23
			// 
			this->panel23->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->panel23->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel23->Location = System::Drawing::Point(693, 113);
			this->panel23->Name = L"panel23";
			this->panel23->Size = System::Drawing::Size(10, 22);
			this->panel23->TabIndex = 38;
			// 
			// panel24
			// 
			this->panel24->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->panel24->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel24->Location = System::Drawing::Point(694, 125);
			this->panel24->Name = L"panel24";
			this->panel24->Size = System::Drawing::Size(208, 10);
			this->panel24->TabIndex = 37;
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->label14->Font = (gcnew System::Drawing::Font(L"Century Gothic", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label14->Location = System::Drawing::Point(677, 70);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(257, 40);
			this->label14->TabIndex = 36;
			this->label14->Text = L"yyyy / MM / dd";
			// 
			// panel25
			// 
			this->panel25->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->panel25->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel25->Location = System::Drawing::Point(691, 43);
			this->panel25->Name = L"panel25";
			this->panel25->Size = System::Drawing::Size(207, 10);
			this->panel25->TabIndex = 35;
			// 
			// panel26
			// 
			this->panel26->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"panel26.BackgroundImage")));
			this->panel26->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel26->Controls->Add(this->textBox14);
			this->panel26->Controls->Add(this->radioButton6);
			this->panel26->Controls->Add(this->panel28);
			this->panel26->Controls->Add(this->panel27);
			this->panel26->Controls->Add(this->textBox11);
			this->panel26->Controls->Add(this->button18);
			this->panel26->Controls->Add(this->dateTimePicker3);
			this->panel26->Controls->Add(this->textBox12);
			this->panel26->Controls->Add(this->textBox13);
			this->panel26->Controls->Add(this->label19);
			this->panel26->Controls->Add(this->radioButton3);
			this->panel26->Controls->Add(this->radioButton4);
			this->panel26->Controls->Add(this->radioButton5);
			this->panel26->Controls->Add(this->listBox1);
			this->panel26->Location = System::Drawing::Point(277, 183);
			this->panel26->Name = L"panel26";
			this->panel26->Size = System::Drawing::Size(1047, 487);
			this->panel26->TabIndex = 33;
			// 
			// textBox14
			// 
			this->textBox14->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox14->Location = System::Drawing::Point(714, 150);
			this->textBox14->Name = L"textBox14";
			this->textBox14->Size = System::Drawing::Size(307, 32);
			this->textBox14->TabIndex = 26;
			this->textBox14->Text = L"            Search by Priority";
			this->textBox14->Click += gcnew System::EventHandler(this, &Form1::textBox14_Click);
			// 
			// radioButton6
			// 
			this->radioButton6->AutoSize = true;
			this->radioButton6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(232)), static_cast<System::Int32>(static_cast<System::Byte>(232)), 
				static_cast<System::Int32>(static_cast<System::Byte>(232)));
			this->radioButton6->Font = (gcnew System::Drawing::Font(L"Consolas", 10.8F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->radioButton6->ForeColor = System::Drawing::Color::Maroon;
			this->radioButton6->Location = System::Drawing::Point(506, 148);
			this->radioButton6->Name = L"radioButton6";
			this->radioButton6->Size = System::Drawing::Size(141, 26);
			this->radioButton6->TabIndex = 25;
			this->radioButton6->TabStop = true;
			this->radioButton6->Text = L"By Priority";
			this->radioButton6->UseVisualStyleBackColor = false;
			this->radioButton6->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton6_CheckedChanged);
			// 
			// panel28
			// 
			this->panel28->BackColor = System::Drawing::Color::DarkOrange;
			this->panel28->Location = System::Drawing::Point(0, 477);
			this->panel28->Name = L"panel28";
			this->panel28->Size = System::Drawing::Size(1049, 10);
			this->panel28->TabIndex = 24;
			// 
			// panel27
			// 
			this->panel27->BackColor = System::Drawing::Color::DarkOrange;
			this->panel27->Location = System::Drawing::Point(1, 2);
			this->panel27->Name = L"panel27";
			this->panel27->Size = System::Drawing::Size(1045, 10);
			this->panel27->TabIndex = 23;
			// 
			// textBox11
			// 
			this->textBox11->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(232)), static_cast<System::Int32>(static_cast<System::Byte>(232)), 
				static_cast<System::Int32>(static_cast<System::Byte>(232)));
			this->textBox11->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox11->Location = System::Drawing::Point(501, 188);
			this->textBox11->Multiline = true;
			this->textBox11->Name = L"textBox11";
			this->textBox11->ReadOnly = true;
			this->textBox11->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox11->Size = System::Drawing::Size(532, 280);
			this->textBox11->TabIndex = 22;
			this->textBox11->Visible = false;
			// 
			// button18
			// 
			this->button18->BackColor = System::Drawing::Color::CornflowerBlue;
			this->button18->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button18->Font = (gcnew System::Drawing::Font(L"Consolas", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button18->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->button18->Location = System::Drawing::Point(327, 386);
			this->button18->Name = L"button18";
			this->button18->Size = System::Drawing::Size(146, 71);
			this->button18->TabIndex = 21;
			this->button18->Text = L"Search";
			this->button18->UseVisualStyleBackColor = false;
			this->button18->Click += gcnew System::EventHandler(this, &Form1::button18_Click);
			// 
			// dateTimePicker3
			// 
			this->dateTimePicker3->CalendarFont = (gcnew System::Drawing::Font(L"TeamViewer13", 12.6F, System::Drawing::FontStyle::Bold));
			this->dateTimePicker3->CalendarForeColor = System::Drawing::Color::Brown;
			this->dateTimePicker3->CalendarMonthBackground = System::Drawing::SystemColors::Control;
			this->dateTimePicker3->CalendarTitleForeColor = System::Drawing::Color::Brown;
			this->dateTimePicker3->CalendarTrailingForeColor = System::Drawing::SystemColors::Desktop;
			this->dateTimePicker3->CustomFormat = L"yyyy-MM-dd";
			this->dateTimePicker3->Font = (gcnew System::Drawing::Font(L"Tahoma", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->dateTimePicker3->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dateTimePicker3->Location = System::Drawing::Point(772, 114);
			this->dateTimePicker3->Name = L"dateTimePicker3";
			this->dateTimePicker3->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->dateTimePicker3->Size = System::Drawing::Size(179, 32);
			this->dateTimePicker3->TabIndex = 20;
			this->dateTimePicker3->Value = System::DateTime(2018, 5, 4, 0, 0, 0, 0);
			// 
			// textBox12
			// 
			this->textBox12->Font = (gcnew System::Drawing::Font(L"Century Gothic", 13.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox12->Location = System::Drawing::Point(714, 78);
			this->textBox12->Name = L"textBox12";
			this->textBox12->Size = System::Drawing::Size(307, 34);
			this->textBox12->TabIndex = 19;
			this->textBox12->Text = L"              Search by id";
			this->textBox12->Click += gcnew System::EventHandler(this, &Form1::textBox12_Click);
			// 
			// textBox13
			// 
			this->textBox13->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox13->Location = System::Drawing::Point(714, 41);
			this->textBox13->Name = L"textBox13";
			this->textBox13->Size = System::Drawing::Size(307, 32);
			this->textBox13->TabIndex = 18;
			this->textBox13->Text = L"             Search by name";
			this->textBox13->Click += gcnew System::EventHandler(this, &Form1::textBox13_Click);
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(232)), static_cast<System::Int32>(static_cast<System::Byte>(232)), 
				static_cast<System::Int32>(static_cast<System::Byte>(232)));
			this->label19->Font = (gcnew System::Drawing::Font(L"Consolas", 13.8F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label19->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label19->Location = System::Drawing::Point(504, 23);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(181, 28);
			this->label19->TabIndex = 17;
			this->label19->Text = L"Search Method";
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(232)), static_cast<System::Int32>(static_cast<System::Byte>(232)), 
				static_cast<System::Int32>(static_cast<System::Byte>(232)));
			this->radioButton3->Font = (gcnew System::Drawing::Font(L"Consolas", 10.8F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->radioButton3->ForeColor = System::Drawing::Color::Maroon;
			this->radioButton3->Location = System::Drawing::Point(506, 114);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(101, 26);
			this->radioButton3->TabIndex = 16;
			this->radioButton3->TabStop = true;
			this->radioButton3->Text = L"By Date";
			this->radioButton3->UseVisualStyleBackColor = false;
			this->radioButton3->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton3_CheckedChanged);
			// 
			// radioButton4
			// 
			this->radioButton4->AutoSize = true;
			this->radioButton4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(232)), static_cast<System::Int32>(static_cast<System::Byte>(232)), 
				static_cast<System::Int32>(static_cast<System::Byte>(232)));
			this->radioButton4->Font = (gcnew System::Drawing::Font(L"Consolas", 10.8F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->radioButton4->ForeColor = System::Drawing::Color::Maroon;
			this->radioButton4->Location = System::Drawing::Point(506, 80);
			this->radioButton4->Name = L"radioButton4";
			this->radioButton4->Size = System::Drawing::Size(81, 26);
			this->radioButton4->TabIndex = 15;
			this->radioButton4->TabStop = true;
			this->radioButton4->Text = L"By ID";
			this->radioButton4->UseVisualStyleBackColor = false;
			this->radioButton4->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton4_CheckedChanged);
			// 
			// radioButton5
			// 
			this->radioButton5->AutoSize = true;
			this->radioButton5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(232)), static_cast<System::Int32>(static_cast<System::Byte>(232)), 
				static_cast<System::Int32>(static_cast<System::Byte>(232)));
			this->radioButton5->Font = (gcnew System::Drawing::Font(L"Consolas", 10.8F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->radioButton5->ForeColor = System::Drawing::Color::Maroon;
			this->radioButton5->Location = System::Drawing::Point(506, 49);
			this->radioButton5->Name = L"radioButton5";
			this->radioButton5->Size = System::Drawing::Size(101, 26);
			this->radioButton5->TabIndex = 14;
			this->radioButton5->TabStop = true;
			this->radioButton5->Text = L"By Name";
			this->radioButton5->UseVisualStyleBackColor = false;
			this->radioButton5->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton5_CheckedChanged);
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 16;
			this->listBox1->Location = System::Drawing::Point(501, 18);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(200, 164);
			this->listBox1->TabIndex = 13;
			this->listBox1->Visible = false;
			// 
			// panel29
			// 
			this->panel29->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(240)), 
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->panel29->Controls->Add(this->label30);
			this->panel29->Controls->Add(this->label29);
			this->panel29->Controls->Add(this->label28);
			this->panel29->Controls->Add(this->label27);
			this->panel29->Controls->Add(this->label26);
			this->panel29->Controls->Add(this->panel34);
			this->panel29->Controls->Add(this->label25);
			this->panel29->Controls->Add(this->label24);
			this->panel29->Controls->Add(this->label23);
			this->panel29->Controls->Add(this->label22);
			this->panel29->Controls->Add(this->label21);
			this->panel29->Controls->Add(this->label20);
			this->panel29->Controls->Add(this->label18);
			this->panel29->Controls->Add(this->label17);
			this->panel29->Controls->Add(this->label16);
			this->panel29->Controls->Add(this->label15);
			this->panel29->Controls->Add(this->panel33);
			this->panel29->Controls->Add(this->panel32);
			this->panel29->Controls->Add(this->panel31);
			this->panel29->Controls->Add(this->panel30);
			this->panel29->Location = System::Drawing::Point(277, 183);
			this->panel29->Name = L"panel29";
			this->panel29->Size = System::Drawing::Size(1047, 487);
			this->panel29->TabIndex = 34;
			// 
			// label30
			// 
			this->label30->AutoSize = true;
			this->label30->Font = (gcnew System::Drawing::Font(L"Adobe Fan Heiti Std B", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->label30->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label30->Location = System::Drawing::Point(149, 74);
			this->label30->Name = L"label30";
			this->label30->Size = System::Drawing::Size(113, 30);
			this->label30->TabIndex = 21;
			this->label30->Text = L"ToDo List";
			// 
			// label29
			// 
			this->label29->AutoSize = true;
			this->label29->Font = (gcnew System::Drawing::Font(L"Adobe Fan Heiti Std B", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->label29->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->label29->Location = System::Drawing::Point(42, 70);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(101, 30);
			this->label29->TabIndex = 20;
			this->label29->Text = L"Project :";
			// 
			// label28
			// 
			this->label28->AutoSize = true;
			this->label28->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label28->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label28->Location = System::Drawing::Point(455, 431);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(271, 29);
			this->label28->TabIndex = 19;
			this->label28->Text = L"7) Samir Abo El Haggag";
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->Font = (gcnew System::Drawing::Font(L"Adobe Fan Heiti Std B", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->label27->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label27->Location = System::Drawing::Point(112, 141);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(163, 30);
			this->label27->TabIndex = 18;
			this->label27->Text = L"Marwa Rafaat";
			// 
			// label26
			// 
			this->label26->AutoSize = true;
			this->label26->Font = (gcnew System::Drawing::Font(L"Adobe Fan Heiti Std B", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->label26->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label26->Location = System::Drawing::Point(170, 108);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(122, 30);
			this->label26->TabIndex = 17;
			this->label26->Text = L"Sally Saad";
			// 
			// panel34
			// 
			this->panel34->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(178)), static_cast<System::Int32>(static_cast<System::Byte>(8)), 
				static_cast<System::Int32>(static_cast<System::Byte>(55)));
			this->panel34->Location = System::Drawing::Point(408, 64);
			this->panel34->Name = L"panel34";
			this->panel34->Size = System::Drawing::Size(154, 10);
			this->panel34->TabIndex = 16;
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label25->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label25->Location = System::Drawing::Point(455, 396);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(183, 29);
			this->label25->TabIndex = 15;
			this->label25->Text = L"6) Shehab Hany";
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label24->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label24->Location = System::Drawing::Point(454, 360);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(232, 29);
			this->label24->TabIndex = 14;
			this->label24->Text = L"5) Tasneem Mitkees";
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label23->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label23->Location = System::Drawing::Point(454, 316);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(206, 29);
			this->label23->TabIndex = 13;
			this->label23->Text = L"4) Ahmed Mostafa";
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label22->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label22->Location = System::Drawing::Point(455, 277);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(193, 29);
			this->label22->TabIndex = 12;
			this->label22->Text = L"3) Radwa Ayman";
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label21->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label21->Location = System::Drawing::Point(455, 237);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(245, 29);
			this->label21->TabIndex = 11;
			this->label21->Text = L"2) Abdelrhman Refaat";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label20->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label20->Location = System::Drawing::Point(455, 195);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(205, 29);
			this->label20->TabIndex = 10;
			this->label20->Text = L"1) Shehab Ahmed";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label18->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->label18->Location = System::Drawing::Point(417, 144);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(308, 46);
			this->label18->TabIndex = 9;
			this->label18->Text = L"Team Members ";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Font = (gcnew System::Drawing::Font(L"Adobe Fan Heiti Std B", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->label17->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->label17->Location = System::Drawing::Point(39, 139);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(59, 30);
			this->label17->TabIndex = 8;
			this->label17->Text = L"T.A :";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Font = (gcnew System::Drawing::Font(L"Adobe Fan Heiti Std B", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->label16->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->label16->Location = System::Drawing::Point(39, 106);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(125, 30);
			this->label16->TabIndex = 7;
			this->label16->Text = L"Professor :";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"Minion Pro SmBd", 22.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label15->ForeColor = System::Drawing::Color::Maroon;
			this->label15->Location = System::Drawing::Point(313, 13);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(383, 52);
			this->label15->TabIndex = 6;
			this->label15->Text = L"SP Project (2017/2021)";
			// 
			// panel33
			// 
			this->panel33->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(178)), static_cast<System::Int32>(static_cast<System::Byte>(8)), 
				static_cast<System::Int32>(static_cast<System::Byte>(55)));
			this->panel33->Location = System::Drawing::Point(1036, 4);
			this->panel33->Name = L"panel33";
			this->panel33->Size = System::Drawing::Size(10, 474);
			this->panel33->TabIndex = 5;
			// 
			// panel32
			// 
			this->panel32->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(178)), static_cast<System::Int32>(static_cast<System::Byte>(8)), 
				static_cast<System::Int32>(static_cast<System::Byte>(55)));
			this->panel32->Location = System::Drawing::Point(-1, 2);
			this->panel32->Name = L"panel32";
			this->panel32->Size = System::Drawing::Size(10, 484);
			this->panel32->TabIndex = 3;
			// 
			// panel31
			// 
			this->panel31->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(178)), static_cast<System::Int32>(static_cast<System::Byte>(8)), 
				static_cast<System::Int32>(static_cast<System::Byte>(55)));
			this->panel31->Location = System::Drawing::Point(1, 477);
			this->panel31->Name = L"panel31";
			this->panel31->Size = System::Drawing::Size(1048, 10);
			this->panel31->TabIndex = 2;
			// 
			// panel30
			// 
			this->panel30->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(178)), static_cast<System::Int32>(static_cast<System::Byte>(8)), 
				static_cast<System::Int32>(static_cast<System::Byte>(55)));
			this->panel30->Location = System::Drawing::Point(-1, 2);
			this->panel30->Name = L"panel30";
			this->panel30->Size = System::Drawing::Size(1048, 10);
			this->panel30->TabIndex = 0;
			// 
			// panel35
			// 
			this->panel35->Controls->Add(this->panel44);
			this->panel35->Controls->Add(this->panel43);
			this->panel35->Controls->Add(this->panel42);
			this->panel35->Controls->Add(this->panel41);
			this->panel35->Controls->Add(this->panel36);
			this->panel35->Controls->Add(this->label31);
			this->panel35->Controls->Add(this->listView1);
			this->panel35->Location = System::Drawing::Point(277, 183);
			this->panel35->Name = L"panel35";
			this->panel35->Size = System::Drawing::Size(1049, 487);
			this->panel35->TabIndex = 35;
			// 
			// panel44
			// 
			this->panel44->BackColor = System::Drawing::Color::BlueViolet;
			this->panel44->Location = System::Drawing::Point(12, 476);
			this->panel44->Margin = System::Windows::Forms::Padding(4);
			this->panel44->Name = L"panel44";
			this->panel44->Size = System::Drawing::Size(1028, 10);
			this->panel44->TabIndex = 41;
			// 
			// panel43
			// 
			this->panel43->BackColor = System::Drawing::Color::BlueViolet;
			this->panel43->Location = System::Drawing::Point(4, 2);
			this->panel43->Margin = System::Windows::Forms::Padding(4);
			this->panel43->Name = L"panel43";
			this->panel43->Size = System::Drawing::Size(1036, 10);
			this->panel43->TabIndex = 40;
			// 
			// panel42
			// 
			this->panel42->BackColor = System::Drawing::Color::BlueViolet;
			this->panel42->Location = System::Drawing::Point(1, 2);
			this->panel42->Margin = System::Windows::Forms::Padding(4);
			this->panel42->Name = L"panel42";
			this->panel42->Size = System::Drawing::Size(10, 484);
			this->panel42->TabIndex = 39;
			// 
			// panel41
			// 
			this->panel41->BackColor = System::Drawing::Color::BlueViolet;
			this->panel41->Location = System::Drawing::Point(1035, 2);
			this->panel41->Margin = System::Windows::Forms::Padding(4);
			this->panel41->Name = L"panel41";
			this->panel41->Size = System::Drawing::Size(10, 484);
			this->panel41->TabIndex = 38;
			// 
			// panel36
			// 
			this->panel36->BackColor = System::Drawing::Color::White;
			this->panel36->Controls->Add(this->panel40);
			this->panel36->Controls->Add(this->panel39);
			this->panel36->Controls->Add(this->panel38);
			this->panel36->Controls->Add(this->panel37);
			this->panel36->Controls->Add(this->label32);
			this->panel36->Controls->Add(this->button20);
			this->panel36->Controls->Add(this->textBox15);
			this->panel36->Location = System::Drawing::Point(230, 121);
			this->panel36->Margin = System::Windows::Forms::Padding(4);
			this->panel36->Name = L"panel36";
			this->panel36->Size = System::Drawing::Size(510, 306);
			this->panel36->TabIndex = 3;
			this->panel36->Visible = false;
			// 
			// panel40
			// 
			this->panel40->BackColor = System::Drawing::Color::BlueViolet;
			this->panel40->Location = System::Drawing::Point(5, 294);
			this->panel40->Margin = System::Windows::Forms::Padding(4);
			this->panel40->Name = L"panel40";
			this->panel40->Size = System::Drawing::Size(502, 10);
			this->panel40->TabIndex = 40;
			// 
			// panel39
			// 
			this->panel39->BackColor = System::Drawing::Color::BlueViolet;
			this->panel39->Location = System::Drawing::Point(0, 2);
			this->panel39->Margin = System::Windows::Forms::Padding(4);
			this->panel39->Name = L"panel39";
			this->panel39->Size = System::Drawing::Size(509, 10);
			this->panel39->TabIndex = 39;
			// 
			// panel38
			// 
			this->panel38->BackColor = System::Drawing::Color::BlueViolet;
			this->panel38->Location = System::Drawing::Point(0, 2);
			this->panel38->Margin = System::Windows::Forms::Padding(4);
			this->panel38->Name = L"panel38";
			this->panel38->Size = System::Drawing::Size(10, 303);
			this->panel38->TabIndex = 38;
			// 
			// panel37
			// 
			this->panel37->BackColor = System::Drawing::Color::BlueViolet;
			this->panel37->Location = System::Drawing::Point(499, 2);
			this->panel37->Margin = System::Windows::Forms::Padding(4);
			this->panel37->Name = L"panel37";
			this->panel37->Size = System::Drawing::Size(10, 304);
			this->panel37->TabIndex = 37;
			// 
			// label32
			// 
			this->label32->AutoSize = true;
			this->label32->Font = (gcnew System::Drawing::Font(L"Century Schoolbook", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label32->ForeColor = System::Drawing::Color::Maroon;
			this->label32->Location = System::Drawing::Point(157, 20);
			this->label32->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label32->Name = L"label32";
			this->label32->Size = System::Drawing::Size(175, 35);
			this->label32->TabIndex = 36;
			this->label32->Text = L"Details Box";
			// 
			// button20
			// 
			this->button20->FlatAppearance->BorderSize = 0;
			this->button20->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button20->Font = (gcnew System::Drawing::Font(L"Century Gothic", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button20->ForeColor = System::Drawing::Color::White;
			this->button20->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"button20.Image")));
			this->button20->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button20->Location = System::Drawing::Point(454, 15);
			this->button20->Margin = System::Windows::Forms::Padding(4);
			this->button20->Name = L"button20";
			this->button20->Size = System::Drawing::Size(43, 43);
			this->button20->TabIndex = 35;
			this->button20->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button20->UseVisualStyleBackColor = true;
			this->button20->Click += gcnew System::EventHandler(this, &Form1::button20_Click);
			// 
			// textBox15
			// 
			this->textBox15->BackColor = System::Drawing::Color::White;
			this->textBox15->Font = (gcnew System::Drawing::Font(L"Century Gothic", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox15->Location = System::Drawing::Point(17, 60);
			this->textBox15->Margin = System::Windows::Forms::Padding(4);
			this->textBox15->Multiline = true;
			this->textBox15->Name = L"textBox15";
			this->textBox15->ReadOnly = true;
			this->textBox15->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox15->Size = System::Drawing::Size(463, 229);
			this->textBox15->TabIndex = 0;
			// 
			// label31
			// 
			this->label31->AutoSize = true;
			this->label31->Font = (gcnew System::Drawing::Font(L"Century Schoolbook", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label31->ForeColor = System::Drawing::Color::Maroon;
			this->label31->Location = System::Drawing::Point(16, 11);
			this->label31->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label31->Name = L"label31";
			this->label31->Size = System::Drawing::Size(639, 35);
			this->label31->TabIndex = 2;
			this->label31->Text = L"Press on the item ID to show it in full details.";
			// 
			// listView1
			// 
			this->listView1->Activation = System::Windows::Forms::ItemActivation::OneClick;
			this->listView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(6) {this->ID, this->Title, 
				this->Priority, this->Overdue, this->Details, this->columnHeader1});
			this->listView1->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->listView1->ForeColor = System::Drawing::Color::BlueViolet;
			this->listView1->HoverSelection = true;
			this->listView1->Location = System::Drawing::Point(3, 55);
			this->listView1->Margin = System::Windows::Forms::Padding(4);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(1033, 423);
			this->listView1->TabIndex = 1;
			this->listView1->UseCompatibleStateImageBehavior = false;
			this->listView1->View = System::Windows::Forms::View::Details;
			this->listView1->Click += gcnew System::EventHandler(this, &Form1::listView1_Click);
			// 
			// ID
			// 
			this->ID->Text = L"ID";
			this->ID->Width = 51;
			// 
			// Title
			// 
			this->Title->Text = L"Title";
			this->Title->Width = 147;
			// 
			// Priority
			// 
			this->Priority->Text = L"Priority";
			this->Priority->Width = 54;
			// 
			// Overdue
			// 
			this->Overdue->Text = L"Overdue";
			this->Overdue->Width = 90;
			// 
			// Details
			// 
			this->Details->Text = L"Details";
			this->Details->Width = 180;
			// 
			// columnHeader1
			// 
			this->columnHeader1->Text = L"State";
			// 
			// listView2
			// 
			this->listView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(6) {this->iID, this->iTitle, 
				this->iPriority, this->iOverdue, this->iDetails, this->iState});
			this->listView2->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->listView2->ForeColor = System::Drawing::SystemColors::Highlight;
			this->listView2->Location = System::Drawing::Point(7, 49);
			this->listView2->Margin = System::Windows::Forms::Padding(4);
			this->listView2->Name = L"listView2";
			this->listView2->Size = System::Drawing::Size(1033, 428);
			this->listView2->TabIndex = 1;
			this->listView2->UseCompatibleStateImageBehavior = false;
			this->listView2->View = System::Windows::Forms::View::Details;
			this->listView2->Click += gcnew System::EventHandler(this, &Form1::listView2_Click);
			// 
			// iID
			// 
			this->iID->Text = L"ID";
			this->iID->Width = 74;
			// 
			// iTitle
			// 
			this->iTitle->Text = L"Title";
			this->iTitle->Width = 135;
			// 
			// iPriority
			// 
			this->iPriority->Text = L"Priority";
			this->iPriority->Width = 64;
			// 
			// iOverdue
			// 
			this->iOverdue->Text = L"Overdue";
			this->iOverdue->Width = 126;
			// 
			// iDetails
			// 
			this->iDetails->Text = L"Details";
			this->iDetails->Width = 281;
			// 
			// iState
			// 
			this->iState->Text = L"State";
			this->iState->Width = 88;
			// 
			// label33
			// 
			this->label33->AutoSize = true;
			this->label33->Font = (gcnew System::Drawing::Font(L"Century Schoolbook", 18));
			this->label33->ForeColor = System::Drawing::Color::Maroon;
			this->label33->Location = System::Drawing::Point(6, 11);
			this->label33->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label33->Name = L"label33";
			this->label33->Size = System::Drawing::Size(639, 35);
			this->label33->TabIndex = 2;
			this->label33->Text = L"Press on the item ID to show it in full details.";
			// 
			// panel46
			// 
			this->panel46->BackColor = System::Drawing::Color::White;
			this->panel46->Controls->Add(this->panel54);
			this->panel46->Controls->Add(this->panel53);
			this->panel46->Controls->Add(this->panel52);
			this->panel46->Controls->Add(this->panel51);
			this->panel46->Controls->Add(this->label34);
			this->panel46->Controls->Add(this->button19);
			this->panel46->Controls->Add(this->textBox16);
			this->panel46->Location = System::Drawing::Point(272, 134);
			this->panel46->Margin = System::Windows::Forms::Padding(4);
			this->panel46->Name = L"panel46";
			this->panel46->Size = System::Drawing::Size(493, 293);
			this->panel46->TabIndex = 3;
			this->panel46->Visible = false;
			// 
			// panel54
			// 
			this->panel54->BackColor = System::Drawing::SystemColors::Highlight;
			this->panel54->Location = System::Drawing::Point(482, 0);
			this->panel54->Name = L"panel54";
			this->panel54->Size = System::Drawing::Size(10, 291);
			this->panel54->TabIndex = 41;
			// 
			// panel53
			// 
			this->panel53->BackColor = System::Drawing::SystemColors::Highlight;
			this->panel53->Location = System::Drawing::Point(0, 5);
			this->panel53->Name = L"panel53";
			this->panel53->Size = System::Drawing::Size(10, 282);
			this->panel53->TabIndex = 40;
			// 
			// panel52
			// 
			this->panel52->BackColor = System::Drawing::SystemColors::Highlight;
			this->panel52->Location = System::Drawing::Point(2, 0);
			this->panel52->Name = L"panel52";
			this->panel52->Size = System::Drawing::Size(492, 10);
			this->panel52->TabIndex = 39;
			// 
			// panel51
			// 
			this->panel51->BackColor = System::Drawing::SystemColors::Highlight;
			this->panel51->Location = System::Drawing::Point(0, 281);
			this->panel51->Name = L"panel51";
			this->panel51->Size = System::Drawing::Size(491, 10);
			this->panel51->TabIndex = 38;
			// 
			// label34
			// 
			this->label34->AutoSize = true;
			this->label34->Font = (gcnew System::Drawing::Font(L"Century Schoolbook", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label34->ForeColor = System::Drawing::Color::Maroon;
			this->label34->Location = System::Drawing::Point(143, 14);
			this->label34->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label34->Name = L"label34";
			this->label34->Size = System::Drawing::Size(175, 35);
			this->label34->TabIndex = 37;
			this->label34->Text = L"Details Box";
			// 
			// button19
			// 
			this->button19->FlatAppearance->BorderSize = 0;
			this->button19->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button19->Font = (gcnew System::Drawing::Font(L"Century Gothic", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button19->ForeColor = System::Drawing::Color::White;
			this->button19->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"button19.Image")));
			this->button19->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button19->Location = System::Drawing::Point(432, 13);
			this->button19->Margin = System::Windows::Forms::Padding(4);
			this->button19->Name = L"button19";
			this->button19->Size = System::Drawing::Size(43, 43);
			this->button19->TabIndex = 36;
			this->button19->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button19->UseVisualStyleBackColor = true;
			this->button19->Click += gcnew System::EventHandler(this, &Form1::button19_Click);
			// 
			// textBox16
			// 
			this->textBox16->BackColor = System::Drawing::Color::White;
			this->textBox16->Font = (gcnew System::Drawing::Font(L"Tahoma", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox16->Location = System::Drawing::Point(21, 59);
			this->textBox16->Margin = System::Windows::Forms::Padding(4);
			this->textBox16->Multiline = true;
			this->textBox16->Name = L"textBox16";
			this->textBox16->ReadOnly = true;
			this->textBox16->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->textBox16->Size = System::Drawing::Size(454, 215);
			this->textBox16->TabIndex = 0;
			// 
			// panel47
			// 
			this->panel47->BackColor = System::Drawing::SystemColors::Highlight;
			this->panel47->Location = System::Drawing::Point(1036, 0);
			this->panel47->Name = L"panel47";
			this->panel47->Size = System::Drawing::Size(10, 486);
			this->panel47->TabIndex = 4;
			// 
			// panel48
			// 
			this->panel48->BackColor = System::Drawing::SystemColors::Highlight;
			this->panel48->Location = System::Drawing::Point(0, 1);
			this->panel48->Name = L"panel48";
			this->panel48->Size = System::Drawing::Size(10, 486);
			this->panel48->TabIndex = 5;
			// 
			// panel49
			// 
			this->panel49->BackColor = System::Drawing::SystemColors::Highlight;
			this->panel49->Location = System::Drawing::Point(1, 0);
			this->panel49->Name = L"panel49";
			this->panel49->Size = System::Drawing::Size(1042, 10);
			this->panel49->TabIndex = 6;
			// 
			// panel50
			// 
			this->panel50->BackColor = System::Drawing::SystemColors::Highlight;
			this->panel50->Location = System::Drawing::Point(4, 476);
			this->panel50->Name = L"panel50";
			this->panel50->Size = System::Drawing::Size(1037, 10);
			this->panel50->TabIndex = 7;
			// 
			// panel45
			// 
			this->panel45->Controls->Add(this->panel50);
			this->panel45->Controls->Add(this->panel49);
			this->panel45->Controls->Add(this->panel48);
			this->panel45->Controls->Add(this->panel47);
			this->panel45->Controls->Add(this->panel46);
			this->panel45->Controls->Add(this->label33);
			this->panel45->Controls->Add(this->listView2);
			this->panel45->Location = System::Drawing::Point(277, 183);
			this->panel45->Name = L"panel45";
			this->panel45->Size = System::Drawing::Size(1047, 487);
			this->panel45->TabIndex = 36;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1323, 670);
			this->Controls->Add(this->panel45);
			this->Controls->Add(this->panel35);
			this->Controls->Add(this->panel29);
			this->Controls->Add(this->panel26);
			this->Controls->Add(this->panel17);
			this->Controls->Add(this->panel9);
			this->Controls->Add(this->panel7);
			this->Controls->Add(this->panel6);
			this->Controls->Add(this->panel5);
			this->Controls->Add(this->panel4);
			this->Controls->Add(this->button11);
			this->Controls->Add(this->button13);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button15);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox2))->EndInit();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox3))->EndInit();
			this->panel5->ResumeLayout(false);
			this->panel5->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox8))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox5))->EndInit();
			this->panel6->ResumeLayout(false);
			this->panel6->PerformLayout();
			this->panel7->ResumeLayout(false);
			this->panel7->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox9))->EndInit();
			this->panel9->ResumeLayout(false);
			this->panel9->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox10))->EndInit();
			this->panel17->ResumeLayout(false);
			this->panel17->PerformLayout();
			this->panel26->ResumeLayout(false);
			this->panel26->PerformLayout();
			this->panel29->ResumeLayout(false);
			this->panel29->PerformLayout();
			this->panel35->ResumeLayout(false);
			this->panel35->PerformLayout();
			this->panel36->ResumeLayout(false);
			this->panel36->PerformLayout();
			this->panel46->ResumeLayout(false);
			this->panel46->PerformLayout();
			this->panel45->ResumeLayout(false);
			this->panel45->PerformLayout();
			this->ResumeLayout(false);

		}



// when minimize button clicked
private: System::Void button11_Click_1(System::Object^  sender, System::EventArgs^  e) { 
			  WindowState = FormWindowState::Minimized;        // minimize  all app button
		 }

// when exit button clicked
private: System::Void button13_Click(System::Object^  sender, System::EventArgs^  e) { 
			 Application::Exit();                          // exit from all app button 
		 }

//when todo lists button clicked
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) { 
			SidePanel->Height = button3->Height;       // main page ->side panel control
			SidePanel->Top = button3->Top;	          //main page -> side panel control
	///---------------------------------------------------
				//hide and show
			panel4->Visible=false;                 // home button panel (hide)
			panel5->Visible=false;                // add new task button panel (hide)
			panel6->Visible=false;               // remove button panel (hide)
			panel7->Visible=false;              // edit button panel (hide)
			panel9->Visible=false;             // todo today  button panel (hide)
			panel17->Visible=false;           // overdue button panel (hide)
			panel26->Visible=false;          // search button panel (hide)
			panel29->Visible=false;         // question mark button panel(hide)
			panel35->Visible=true;         // todo lists button panel (show)
			panel45->Visible=false;       // done button panel (hide)
			panel36->Visible=false;      // todo list details box (hide)
	///---------------------------------------------------
			FillTodolistListView();    // re fill list view on todo lists panel
		 }

//  when home button clicked
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			SidePanel->Height = button1->Height;         // main page ->side panel control
			SidePanel->Top = button1->Top;              // main page ->side panel control
	///---------------------------------------------------
				//hide and show
			panel4->Visible=true;                    // home button panel (show)
			panel5->Visible=false;                  // add new task button panel (hide)
			panel6->Visible=false;                 // remove button panel (hide)
			panel7->Visible=false;                // edit button panel (hide)
			panel9->Visible=false;               // todo today button panel (hide)
			panel17->Visible=false;             // overdue button banel (hide)
			panel26->Visible=false;            // search button panel (hide)
			panel29->Visible=false;           // question mark button panel(hide)
			panel35->Visible=false;          // todo lists button panel (hide)
			panel45->Visible=false;         // done button panel (hide)
	///---------------------------------------------------	
		 }

//when todo today button clicked
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) { 
			 SidePanel->Height = button2->Height;     // main page ->side panel control
			 SidePanel->Top = button2->Top;          // main page ->side panel control
	///---------------------------------------------------
				//hide and show
			panel4->Visible=false;                //  home button panel (hide)
			panel5->Visible=false;               // add new task button panel (hide)
			panel6->Visible=false;              // remove button panel (hide)
			panel7->Visible=false;             // edit button panel (hide)
			panel9->Visible=true;             // todo today button panel (show)
			panel17->Visible=false;          // overdue button banel (hide)
			panel26->Visible=false;         // search button panel (hide)
			panel29->Visible=false;        // question mark button panel(hide)
			panel35->Visible=false;       // todo lists button panel (hide)
			panel45->Visible=false;      // done button panel (hide)
	///---------------------------------------------------
			 textBox8->Visible=false;
			 radioButton1->Visible=false;
			 radioButton2->Visible=false;

			 comboBox3->Text="                     Tasks ToDo Today";

			 DateTime date = DateTime::Now; 
			 String^ nowdate = date.ToString ("yyyy / MM / dd");

			 label13 ->Text=nowdate; // date label on todo today
		 }

//when done button clicked
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) { 
			 SidePanel->Height = button4->Height;    //main page -> side panel control
			 SidePanel->Top = button4->Top;         // main page ->side panel control
		///---------------------------------------------------
				//hide and show
			panel4->Visible=false;               // home button panel (hide)
			panel5->Visible=false;              // add new task button panel (hide)
			panel6->Visible=false;             // remove button panel (hide)
			panel7->Visible=false;            // edit button panel (hide)
			panel9->Visible=false;           // todo today panel (hide)
			panel17->Visible=false;         // overdue button banel (hide)
			panel26->Visible=false;        // search button panel (hide)
			panel29->Visible=false;       // question mark button panel(hide)
			panel35->Visible=false;      // todo lists button panel (hide)
			panel45->Visible=true;      // done button panel (show)
			panel46->Visible=false;    // details box on done panel (hide)
	///---------------------------------------------------
			FillDoneListView();      // re fill list view on done panel
		 }

//when overdue button clicked 
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) { 
			 SidePanel->Height = button5->Height;    // main page ->side panel control
			 SidePanel->Top = button5->Top;         // main page ->side panel control
		///---------------------------------------------------
				//hide and show
			panel4->Visible=false;              // home button panel (hide)
			panel5->Visible=false;             // add new task button panel (hide)
			panel6->Visible=false;            // remove button panel (hide)
			panel7->Visible=false;           // edit button panel (hide)
			panel9->Visible=false;          // todo today panel (hide)
			panel17->Visible=true;         // overdue button panel (show)
			panel26->Visible=false;       // search button panel (hide)
			panel29->Visible=false;      // question mark button panel(hide)
			panel35->Visible=false;     // todo lists button panel (hide)
			panel45->Visible=false;    // done button panel (hide)
	///---------------------------------------------------
			textBox10->Visible =false ;

			DateTime date = DateTime::Now; 
			 String^ nowdate = date.ToString ("yyyy / MM / dd");

			 label14 ->Text=nowdate; // date label on over due panel

		
		 }

//when edit button clicked
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) { 
			 SidePanel->Height = button6->Height;      // main page ->side panel control
			 SidePanel->Top = button6->Top;           // main page ->side panel control
	///---------------------------------------------------
				//hide and show
			panel4->Visible=false;                  // home button panel (hide)
			panel5->Visible=false;                 //  add new task button panel (hide)
			panel6->Visible=false;                // remove button panel (hide)
			panel7->Visible=true;                // edit button panel (show)
			panel9->Visible=false;              // todo today panel (hide)
			panel17->Visible=false;            // overdue button banel (hide)
			panel26->Visible=false;           // search button panel (hide)
			panel29->Visible=false;          // question mark button panel(hide)
			panel35->Visible=false;         // todo lists button panel (hide)
			panel45->Visible=false;        // done button panel (hide)
	///---------------------------------------------------
			//----checkbox 1 on edit panel ----
			checkBox1->Text = L"Statue"; 
			checkBox1->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			checkBox1->Checked=false;
			//--------------------clear edit panel text boxes-----------------------
			textBox5->Clear();
			textBox6->Clear();
			textBox7->Clear();
			textBox9->Clear();
			comboBox2->Text = L"                    Select Task";
			dateTimePicker2->ResetText(); //reset date time picker date to this moment date
		 }

 // when remove button clicked
private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) { 
			 SidePanel->Height = button7->Height;        //  main page -> side panel control
			 SidePanel->Top = button7->Top;             //  main page -> side panel control
		///---------------------------------------------------
				//hide and show
			panel4->Visible=false;                    //   home button panel (hide)
			panel5->Visible=false;                   //  add new task button panel (hide)
			panel6->Visible=true;                   //remove button panel (show)
			panel7->Visible=false;                 // edit button panel (hide)
			panel9->Visible=false;                // todo today button panel (hide)
			panel17->Visible=false;              // overdue button banel (hide)
			panel26->Visible=false;             // search button panel (hide)
			panel29->Visible=false;            // question mark button panel(hide)
			panel35->Visible=false;           // todo lists button panel (hide)
			panel45->Visible=false;          // done button panel (hide)
	   ///---------------------------------------------------
			 textBox1->Visible=false; 
			 btnRemoveCombo->Visible=false;
			 comboBox1->Text = L"                    Select Task";
		 }

 //when search button clicked
private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {
			 SidePanel->Height = button8->Height;    //  main page -> side panel control
			 SidePanel->Top = button8->Top;         //  main page -> side panel control
	///---------------------------------------------------
			//hide and show 
			panel4->Visible=false;               // home button panel (hide)
			panel5->Visible=false;              //  add new task button panel (hide)
			panel6->Visible=false;             // remove button panel (hide)
			panel7->Visible=false;            // edit button panel (hide)
			panel9->Visible=false;           // todo today button panel (hide)
			panel17->Visible=false;         // overdue button banel (hide)
			panel26->Visible=true;         // search button panel (show)
			panel29->Visible=false;       // question mark button panel(hide)
			panel35->Visible=false;      // todo lists button panel (hide)
			panel45->Visible=false;     // done button panel (hide)
	///---------------------------------------------------
			 textBox13->Visible=false;
			 textBox12->Visible=false;
			 textBox11->Visible=false;
			 textBox14->Visible=false;
			 dateTimePicker3->Visible=false;
			 radioButton3->Checked=false;
			 radioButton4->Checked=false;
			 radioButton5->Checked=false;
			 radioButton6->Checked=false;
			 textBox11->ResetText();
			 dateTimePicker3->ResetText();
			 textBox12->Text="              Search by id";
			 textBox13->Text="              Search by name";
			 textBox14->Text="             Search by Priority";
		    
		 }

//when question mark on side buttons bar clicked
private: System::Void button14_Click(System::Object^  sender, System::EventArgs^  e) { 
			  SidePanel->Height = button14->Height;     // home page ->side panel control
			  SidePanel->Top = button14->Top;          //home page  ->side panel control
	///---------------------------------------------------
				//hide and show
			panel4->Visible=false;                  // home button panel (hide)
			panel5->Visible=false;                 // add new task button panel (hide)
			panel6->Visible=false;                // remove button panel (hide)
			panel7->Visible=false;               // edit butto panel (hide)
			panel9->Visible=false;              // todo today button panel (hide)
			panel29->Visible=true;             // question mark button panel(show)
			panel26->Visible=false;           // search button panel (hide)
			panel35->Visible=false;          // todo lists button panel (hide)
			panel45->Visible=false;         // done button panel (hide)
	///---------------------------------------------------
			
		 }

// when add new task button clicked
private: System::Void button12_Click(System::Object^  sender, System::EventArgs^  e) { 
			///---------------------------------------------------
					 //hide and show
			panel4->Visible=false;               // home button panel (hide)
			panel5->Visible=true;               // add new task button panel (hide)
			panel6->Visible=false;             // remove button panel (hide)
			panel7->Visible=false;            // edit butto panel (hide)
			panel9->Visible=false;           // todo today button panel (hide)
			panel17->Visible=false;         // overdue button banel (hide)
			panel26->Visible=false;        // search button panel (hide)
			panel35->Visible=false;       // todo lists button panel (hide)
			panel45->Visible=false;      // done button panel (hide)
		  ///---------------------------------------------------
			textBox2->Clear();
			textBox3->Clear();
			textBox4->Clear();
			dateTimePicker1->ResetText();
		 }

// home page -> add task -> add panel ->question marks (id)
private: System::Void pictureBox4_Click(System::Object^  sender, System::EventArgs^  e) {
			 MessageBox::Show("Invalid Input Entered");
		 }

//home page -> add task -> add panel ->question marks (title)
private: System::Void pictureBox5_Click(System::Object^  sender, System::EventArgs^  e) { 
			 MessageBox::Show("Title must be in ranage of 1 - 200 character , it's allowed to use numbers or symbols.");
		 }

// home page -> add task -> add panel ->question marks (periority)
private: System::Void pictureBox6_Click(System::Object^  sender, System::EventArgs^  e) { 
			 MessageBox::Show("What is 'Priority'?\r\na thing that is regarded as more important than others.\r\nyou can set it to a high value to indicate to it's imprortance.\r\nSymbols or letter not allowed.");
		 }

 // home page -> add task -> add panel ->question marks (overdue date)
private: System::Void pictureBox7_Click(System::Object^  sender, System::EventArgs^  e) {
			 MessageBox::Show("Select the date you wish to make a deadline to your task.");
		 }

// home page -> add task -> add panel ->question marks (details)
private: System::Void pictureBox8_Click(System::Object^  sender, System::EventArgs^  e) { 
			MessageBox::Show("Detales of the task, it's allowed to type (Character-Numbers-Symbols-Etc).");
		 }

// home page -> add task -> add panel ->question marks (statue)
private: System::Void pictureBox9_Click(System::Object^  sender, System::EventArgs^  e) { 
		 }

// when add button on add new task panel clicked
private: System::Void button16_Click(System::Object^  sender, System::EventArgs^  e) { 
				  try {
					
					  MySqlConnection^ con= gcnew MySqlConnection( conobj->constr); 

					  
				todoobj->title=textBox2->Text; 
				todoobj-> priority = Int32::Parse(textBox4->Text); 
				todoobj-> overdue =dateTimePicker1->Text; 
				todoobj-> details=textBox3->Text; 
				todoobj->statue ="Not Done";

				 MySqlCommand ^ cmd= gcnew MySqlCommand  
					 ( "insert into todo.list (title ,priority ,overdue ,details ,statue) values ('"+todoobj->title+"',"+todoobj-> priority+"  ,  '"+todoobj-> overdue+"'    ,'"+todoobj-> details+"' ,'"+todoobj-> statue+"')" , con );
				
				 con -> Open(); 
				 MySqlDataReader ^dr; 
				 dr=cmd->ExecuteReader(); 

				 con -> Close();

				 comboBox1->Items->Add(textBox2->Text);    // add the new task to remove combo box
				 comboBox2->Items->Add(textBox2->Text);   // add the new task to edit combo box
				 String^ text=textBox2->Text;
				 Filloveragain();

				 DateTime date = DateTime::Now;                   //story now date
			     String^ nowdate = date.ToString ("yyyy-MM-dd"); // format it

				 if (nowdate == todoobj->overdue) 
					 comboBox3->Items->Add(todoobj->title);
				 

				  addsuccess^ openaddsuccess =gcnew addsuccess(); // show add success form 
				  openaddsuccess ->ShowDialog();       

				  panel4->Visible = true; // home button panel (show)
				  panel5->Visible=false; // add new task button panel (hide)

				 }
				 catch(Exception^ex){  
					 MessageBox::Show(ex ->Message );  
					  MessageBox::Show("Click On Question Mark Icons For More Information" ); 
						}
		 }


// when delete button on remove button panel clicked
private: System::Void btnRemoveCombo_Click(System::Object^  sender, System::EventArgs^  e) { 
			 try{

			MySqlConnection^ con= gcnew MySqlConnection( conobj->constr); 
			
			todoobj->title = comboBox1->Text;
			 
			  MySqlCommand^Cmd = gcnew MySqlCommand
				("delete from todo.list where title = '"+todoobj->title+"';",con); 

			  con->Open();
			  MySqlDataReader^dr;
			 dr = Cmd->ExecuteReader();

			 con ->Close();

			  comboBox2->Items->Remove(comboBox1->Text);    // remove the task from edit panel combo box
			  comboBox1->Items->Remove(comboBox1->Text);   // remove the task from remove panel combo box
			  comboBox3->Items->Remove(comboBox1->Text);  // remove the task from todo today panel combo box
			  comboBox4->Items->Remove(comboBox1->Text); //  remove the task from overdue panel combo box

			 textBox1->Visible=false; //hide details txt box
			 btnRemoveCombo->Visible=false; //hide btnremove
			 comboBox1->Text = L"                    Select Task";

				  addsuccess^ openaddsuccess =gcnew addsuccess(); // show add success form 
				  openaddsuccess ->ShowDialog(); 

			}catch(Exception^ex){
			  
				MessageBox::Show(ex->Message);
			}
		 }

// when combo box on remove panel text changed
private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {  
			  try{
				  textBox1->Visible=true;
				  btnRemoveCombo->Visible=true;

			  MySqlConnection^ con= gcnew MySqlConnection( conobj->constr); 
			
			 todoobj->title =comboBox1->Text;

			 MySqlCommand^cmd = gcnew MySqlCommand
				 ("Select * from todo.list where title = '"+todoobj->title+"';",con);
			
			 con->Open();
			  MySqlDataReader^dr;
			 dr = cmd->ExecuteReader();
			 dr->Read();

			  String^title= dr->GetString("title");
			  String^id = dr->GetString("id");
			  String^priority = dr->GetString("priority");
			  String^date = dr->GetString("overdue");
			  String^statue= dr->GetString("statue");
			  String^detailes=dr->GetString("details");
			 
			   con ->Close();

			 textBox1->Text = "Task Title : " +title + " \r\n";
			   textBox1->Text += "\r\n";
			 textBox1->Text += "Task ID : " +id + "\r\n";
			   textBox1->Text += "\r\n";
			 textBox1->Text += "Task Priority : " +priority + "\r\n";
				textBox1->Text += "\r\n";
			 textBox1->Text += "Overdue Date : " +date + " \r\n";
				textBox1->Text += "\r\n";
			 textBox1->Text += "Task state : " +statue + " \r\n";
				 textBox1->Text += "\r\n";
			 textBox1->Text += "Task Details : " +detailes + " \r\n";
			   textBox1->Text += "\r\n";

			  

			}catch(Exception^ex){
			MessageBox::Show(ex->Message);
			}
		 }


		 // none event Functions begining


//Fill remove and edit panel comboBoxs with data
		  private : void FillRemovalCombo(void){  
			 try{

			MySqlConnection^ con= gcnew MySqlConnection( conobj->constr); 

			MySqlCommand^Cmd = gcnew MySqlCommand
				(" select*from todo.list;",con);

			con->Open();
			MySqlDataReader^dr;
			dr = Cmd -> ExecuteReader();

			while(dr->Read()){
				
			todoobj->title = dr->GetString("title"); 
			comboBox1->Items-> Add(todoobj->title); // remove combo box
			comboBox2->Items->Add(todoobj->title); // edit combo box
			
							}
			con->Close();

			}catch(Exception^ex){
			  MessageBox::Show(ex->Message);
			}
				 }
		 
//fill to do today panel combo box with data
		  private : void FilltodoCombo(void){  
							 
			 try{

		MySqlConnection^ con= gcnew MySqlConnection( conobj->constr); 

			DateTime date = DateTime::Now;                   //story now date
			String^ nowdate = date.ToString ("yyyy-MM-dd"); // format it
			

			MySqlCommand^Cmd = gcnew MySqlCommand
				(" select*from todo.list where overdue='"+nowdate +"' AND statue='Not Done' ;",con);

			con->Open();
			MySqlDataReader^dr;
			dr = Cmd -> ExecuteReader();

			while(dr->Read()){
				todoobj->title=dr->GetString("title");
				comboBox3->Items-> Add(todoobj->title);  // to do today combo box
							}
			con ->Close();

			}catch(Exception^ex){
			  MessageBox::Show(ex->Message);
			}
				 }

// fill overdue panel combo box with data
		  private : void FilloverdueCombo(void){  		 
			 try{

			MySqlConnection^ con= gcnew MySqlConnection( conobj->constr); 

			DateTime date = DateTime::Now;                   //story now date
			String^ nowdate_y = date.ToString("yyyy"); // format it
			String^ nowdate_m = date.ToString("MM");
			String^ nowdate_d = date.ToString("dd");

				int n_yyyy=Int32 ::Parse(nowdate_y);
				int n_mm=Int32 ::Parse(nowdate_m);
				int n_dd=Int32::Parse(nowdate_d);
				

			MySqlCommand^Cmd = gcnew MySqlCommand
				(" select*from todo.list where statue='Not Done' ;",con);

			con->Open();
			MySqlDataReader^dr;
			dr = Cmd -> ExecuteReader();

			
			while(dr->Read()){

				todoobj->title=dr->GetString("title");
				todoobj->overdue=dr->GetString("overdue");

				DateTime overdue=	dr->GetDateTime("overdue");
				String ^ overdue_y=overdue.ToString("yyyy");
				String ^ overdue_m=overdue.ToString("MM");
				String ^ overdue_d=overdue.ToString("dd");

				int o_yyyy=Int32 ::Parse(overdue_y);
				int o_mm=Int32 ::Parse(overdue_m);
				int o_dd=Int32::Parse(overdue_d);

				if (n_yyyy >= o_yyyy){
					if (n_mm >= o_mm){
						if(n_dd > o_dd){
							comboBox4->Items-> Add(todoobj->title);  //overdue combo box
							}
						}
					}
							}
			con ->Close();

			}catch(Exception^ex){
			  MessageBox::Show(ex->Message);
			}
				 }


//search by radio button 5 (by name) on search panel 
					private : void r5 (void){
					  try{

			 MySqlConnection^ con= gcnew MySqlConnection( conobj->constr); 
			
				 todoobj->title = textBox13 ->Text;

			 MySqlCommand^Cmd;
			 Cmd =  gcnew MySqlCommand
				 ("select * from todo.list where title ='"+todoobj->title+"';",con);

			 MySqlDataReader^dr;
			 con->Open();
			 dr = Cmd->ExecuteReader();
			 dr->Read();

			  String ^ title= dr->GetString("title");
			  String^id = dr->GetString("id");
			  String^priority = dr->GetString("priority");
			  String^date = dr->GetString("overdue");
			  String ^statue= dr->GetString("statue");
			  String^detailes=dr->GetString("details");

			  con ->Close();

			 textBox11->Text = "Task Title : " +title + " \r\n";
			 textBox11->Text += "\r\n";
			 textBox11->Text += "Task ID : " +id + "\r\n";
			 textBox11->Text += "\r\n";
			 textBox11->Text += "Task Priority : " +priority + "\r\n";
			 textBox11->Text += "\r\n";
			 textBox11->Text += "Overdue Date : " +date + " \r\n";
			 textBox11->Text += "\r\n";
			 textBox11->Text += "Task state : " +statue + " \r\n";
			 textBox11->Text += "\r\n";
			 textBox11->Text += "Task Details : " +detailes + " \r\n";
			 textBox11->Text += "\r\n";

			  textBox11->Visible=true;
			 
			}catch(Exception^ex){
				MessageBox::Show("Invalid Input Entered");
				textBox11->Visible=false;
				radioButton5->Checked=false;
			textBox13->Text="              Search by name";
			}
	} 

//search by radio button 4 (by id) on search panel 
		  private : void r4 (void){
					   try{

			MySqlConnection^ con= gcnew MySqlConnection( conobj->constr); 

			 todoobj->id = Int32::Parse(textBox12->Text);
			 MySqlCommand^Cmd;
			 Cmd =  gcnew MySqlCommand
				 ("select * from todo.list where id ='"+todoobj->id+"';",con);

			 MySqlDataReader^dr;
			 con->Open();
			 dr = Cmd->ExecuteReader();
			 dr->Read();

			  String ^ title= dr->GetString("title");
			  String^id = dr->GetString("id");
			  String^priority = dr->GetString("priority");
			  String^date = dr->GetString("overdue");
			  String ^statue= dr->GetString("statue");
			  String^detailes=dr->GetString("details");

			  con ->Close();

			 textBox11->Text = "Task Title : " +title + " \r\n";
			 textBox11->Text += "\r\n";
			 textBox11->Text += "Task ID : " +id + "\r\n";
			 textBox11->Text += "\r\n";
			 textBox11->Text += "Task Priority : " +priority + "\r\n";
			 textBox11->Text += "\r\n";
			 textBox11->Text += "Overdue Date : " +date + " \r\n";
			 textBox11->Text += "\r\n";
			 textBox11->Text += "Task state : " +statue + " \r\n";
			 textBox11->Text += "\r\n";
			 textBox11->Text += "Task Details : " +detailes + " \r\n";
			 textBox11->Text += "\r\n";
			  textBox11->Visible=true;

			}catch(Exception^ex){
				MessageBox::Show("Invalid Input Entered");
				radioButton4->Checked=false;
				textBox11->Visible=false;
				textBox12->Text="              Search by id";

			}
				  }

//search by radio button 3 (by date) on search panel 
		  private : void r3 (void){

					  textBox11->ResetText();

					  try{

			 MySqlConnection^ con= gcnew MySqlConnection( conobj->constr); 
			 
			 todoobj->overdue = dateTimePicker3->Text->Substring(0,10);

			MySqlCommand^Cmd;
			 Cmd =  gcnew MySqlCommand
				 ("select * from todo.list where overdue ='"+todoobj->overdue+"';",con);

			 MySqlDataReader^dr;
			 con->Open();
			 dr = Cmd->ExecuteReader();

			 int i=0;

			 while (dr->Read()){
			 
			  String ^ title= dr->GetString("title");
			  String^id = dr->GetString("id");
			  String^priority = dr->GetString("priority");
			  String^date = dr->GetString("overdue");
			  String ^statue= dr->GetString("statue");
			  String^detailes=dr->GetString("details");
			  
			  textBox11->Text += "-------------------------Task Number  " + ++i + "-------------------------\r\n ";
			 textBox11->Text += "Task Title : " +title + " \r\n";
			 textBox11->Text += "\r\n";
			 textBox11->Text += "Task ID : " +id + "\r\n";
			 textBox11->Text += "\r\n";
			 textBox11->Text += "Task Priority : " +priority + "\r\n";
			 textBox11->Text += "\r\n";
			 textBox11->Text += "Overdue Date : " +date + " \r\n";
			 textBox11->Text += "\r\n";
			 textBox11->Text += "Task state : " +statue + " \r\n";
			 textBox11->Text += "\r\n";
			 textBox11->Text += "Task Details : " +detailes + " \r\n";
			 textBox11->Text += "\r\n";
			
			 }

			  con->Close();

			  textBox11->Visible=true;
			 
			 
			}catch(Exception^ex){
				MessageBox::Show("Invalid Input Entered");
				radioButton3->Checked=false;
				textBox11->Visible=false;
				dateTimePicker3->ResetText();
			}

				  }

//search by radio button 6 (by priority) on search panel 
		  private : void r6 (void){
					  textBox11->ResetText();

					   try{

			MySqlConnection^ con= gcnew MySqlConnection( conobj->constr); 
			
			 todoobj->priority = Int32::Parse(textBox14->Text);

			 MySqlCommand^Cmd;
			 Cmd =  gcnew MySqlCommand
				 ("select * from todo.list where priority ="+todoobj->priority+";",con);

			 MySqlDataReader^dr;
			 con->Open();
			 dr = Cmd->ExecuteReader();

			 if (dr->Read()==false) {
				radioButton6->Checked=false;
				textBox11->Visible=false;
				textBox14->Text="              Search by priority";
				con->Close();
			 
			 }
			 
			 textBox11->Text="";
			 int i=0;
	
			while ( dr->Read()){

			  String ^ title= dr->GetString("title");
			  String^id = dr->GetString("id");
			  String^priority = dr->GetString("priority");
			  String^date = dr->GetString("overdue");
			  String ^statue= dr->GetString("statue");
			  String^detailes=dr->GetString("details");

			 textBox11->Text += "-------------------------Task Number  " + ++i + "-------------------------\r\n ";
			 textBox11->Text += "Task Title : " +title + " \r\n";
			 textBox11->Text += "\r\n";
			 textBox11->Text += "Task ID : " +id + "\r\n";
			 textBox11->Text += "\r\n";
			 textBox11->Text += "Task Priority : " +priority + "\r\n";
			 textBox11->Text += "\r\n";
			 textBox11->Text += "Overdue Date : " +date + " \r\n";
			 textBox11->Text += "\r\n";
			 textBox11->Text += "Task state : " +statue + " \r\n";
			 textBox11->Text += "\r\n";
			 textBox11->Text += "Task Details : " +detailes + " \r\n";
			 textBox11->Text += "\r\n";
			}
			
			  con ->Close();
			  textBox11->Visible=true;
			 
			}catch(Exception^ex){
				MessageBox::Show("Invalid Input Entered");
				radioButton6->Checked=false;
				textBox11->Visible=false;
				textBox14->Text="              Search by priority";

			}
						}

 //Listview function to fill todo list items
		  void FillTodolistListView(void)
		 {

			   listView1->Items->Clear();
				try{	

				MySqlConnection^ con= gcnew MySqlConnection(conobj->constr);

				MySqlCommand^cmd = gcnew MySqlCommand
				("Select * from todo.list;" , con);

				MySqlDataReader^dr;
				con->Open();
				dr = cmd-> ExecuteReader();	

			   int i = 0;
	
			   while(dr->Read())              // READING THE DATA FROM DATABASE AND PUT IT INTO THE lISTvIEW 
			   {

				String ^ title= dr->GetString("title");
				String^id = dr->GetString("id");
				String^priority = dr->GetString("priority");
				String^date = dr->GetString("overdue");
				String ^statue= dr->GetString("statue");
				String^details=dr->GetString("details");

				//methood adding items to listview 
				listView1->Items->Add(id);
				listView1->Items[i]->SubItems->Add(title);
				listView1->Items[i]->SubItems->Add(priority);
				listView1->Items[i]->SubItems->Add(date);
				listView1->Items[i]->SubItems->Add(details);
				listView1->Items[i++]->SubItems->Add(statue);
				
				 }

				 con->Close();

				}catch(Exception^ex) {
				  MessageBox::Show(ex->Message);
				}
			 }

//listview function to fill done items
		  void FillDoneListView(void)
			{
			listView2->Items->Clear();

			  try{	

			   MySqlConnection^ con= gcnew MySqlConnection(conobj->constr);

			   MySqlCommand^cmd = gcnew MySqlCommand
				("Select * from todo.list where statue ='Done';" , con);

				MySqlDataReader^dr;
				con->Open();
				dr = cmd-> ExecuteReader();	

				int i = 0;
			 
				while(dr->Read())          // READING THE DATA FROM DATABASE AND PUT IT INTO THE lISTvIEW
				{

				String ^ title= dr->GetString("title");
				String^id = dr->GetString("id");
				String^priority = dr->GetString("priority");
				String^date = dr->GetString("overdue");
				String ^statue= dr->GetString("statue");
				String^details=dr->GetString("details");

				//methood adding items to listview 
				listView2->Items->Add(id);
				listView2->Items[i]->SubItems->Add(title);
				listView2->Items[i]->SubItems->Add(priority);
				listView2->Items[i]->SubItems->Add(date);
				listView2->Items[i]->SubItems->Add(details);
				listView2->Items[i++]->SubItems->Add(statue);
				
				  }

			  con->Close();

			  }catch(Exception^ex) {
				  MessageBox::Show(ex->Message);
			  }
		   }

//fill overdue combo box with add & edit & remove 
		  int Filloveragain( void){
			  try {
				   
				  MySqlConnection ^con =gcnew MySqlConnection(conobj->constr);
				  MySqlCommand^ cmd=gcnew MySqlCommand 
					  ("select*from todo.list where title='"+todoobj->title+"';", con);
				  
				  con->Open();
				  MySqlDataReader ^ dr;
				  dr=cmd->ExecuteReader();
				   dr->Read();

				 DateTime overdue=	dr->GetDateTime("overdue");
				String ^ overdue_y=overdue.ToString("yyyy");
				String ^ overdue_m=overdue.ToString("MM");
				String ^ overdue_d=overdue.ToString("dd");
				  
				int o_yyyy=Int32 ::Parse(overdue_y);
				int o_mm=Int32 ::Parse(overdue_m);
				int o_dd=Int32::Parse(overdue_d);

				DateTime date = DateTime::Now;                   //story now date
				String^ nowdate_y = date.ToString("yyyy"); // format it
				String^ nowdate_m = date.ToString("MM");
				String^ nowdate_d = date.ToString("dd");

				int n_yyyy=Int32 ::Parse(nowdate_y);
				int n_mm=Int32 ::Parse(nowdate_m);
				int n_dd=Int32::Parse(nowdate_d);
				
				if (n_yyyy >= o_yyyy){
					if (n_mm >= o_mm){
						if(n_dd > o_dd){
							comboBox4->Items-> Add(todoobj->title);  //overdue combo box
							}
						}
					}

				con->Close();
				return 0;
			  }catch(Exception^ex){
			  MessageBox::Show(ex->Message);
			}
				}

			 
		  // End of none event functions

// when combo box on edit text changed
private: System::Void comboBox2_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
				 try{

				MySqlConnection^ con= gcnew MySqlConnection( conobj->constr); 

				  todoobj->title=comboBox2->Text;

				 MySqlCommand^cmd=gcnew MySqlCommand
					 ("select * from todo.list where title='"+todoobj->title+"' ", con);

				  con->Open();
				 MySqlDataReader^dr;
					 dr=cmd->ExecuteReader();

				 while(dr->Read()){

						 textBox5->Text=dr->GetString("id");
						 textBox6->Text=dr->GetString("title");
						 textBox7->Text=dr->GetString("priority");
						 dateTimePicker2->Text=dr->GetString("overdue");
						 textBox9->Text=dr->GetString("details");
						 checkBox1->Text=dr->GetString("statue");

						 if (checkBox1->Text=="Done"){
							 checkBox1->Checked=true;
							 checkBox1->ForeColor = System::Drawing::Color::Green;
						 }
						 else if (checkBox1->Text=="Not Done"){
							  checkBox1->Checked=false;
							 checkBox1->ForeColor = System::Drawing::Color::Maroon;
						 }
					}

					 con->Close();

				 }catch(Exception^ex){
					 MessageBox::Show(ex->Message);
				 }
		 }

//when Edit button on Edit panel clicked
private: System::Void button17_Click(System::Object^  sender, System::EventArgs^  e) {
				 try{
			   MySqlConnection^ con= gcnew MySqlConnection( conobj->constr); 

				 todoobj->id=Int32::Parse(textBox5->Text);
				 todoobj->title=textBox6->Text;
				 todoobj->priority=Int32::Parse(textBox7->Text);
				 todoobj->overdue=dateTimePicker2->Text;
				 todoobj->details=textBox9->Text;
				 todoobj->statue=checkBox1->Text;
				 String ^tit=comboBox2->Text;

				 MySqlCommand^cmd=gcnew MySqlCommand
 ("update todo.list set id="+todoobj->id+" , title='"+ todoobj->title+"', priority="+ todoobj->priority+", overdue='"+todoobj->overdue+"', details='"+todoobj->details+"', statue='"+todoobj->statue+"' where title='"+tit+"'   ", con);
				 
					 con->Open();
					 MySqlDataReader^dr=cmd->ExecuteReader();
					  con->Close();

					 addsuccess^ openaddsuccess =gcnew addsuccess(); 
					 openaddsuccess ->ShowDialog();
				 
				 comboBox1->Items->Remove(comboBox2->Text);
				 comboBox1->Items->Add(todoobj->title);
				 comboBox2->Items->Remove(comboBox2->Text);
				 comboBox2->Items->Add(todoobj->title);
				 comboBox3->Items->Remove(comboBox2->Text);
				 comboBox4->Items->Remove(comboBox2->Text);
				 Filloveragain();
				

					 ///----checkbox 1 on edit page -------------------
			checkBox1->Checked=false; // change check box mark 
			checkBox1->Text = L"Statue";
			checkBox1->ForeColor = System::Drawing::SystemColors::ControlDarkDark; // change check box colour
			// -----------------clear edit page when edit button on edit page clicked -------------------
			 comboBox2->Text = L"                    Select Task";
			 textBox5->Clear(); 
			 textBox6->Clear();
			 textBox7->Clear();
			 textBox9->Clear();

			 DateTime date = DateTime::Now;                   //story now date
			 String^ nowdate = date.ToString ("yyyy-MM-dd"); // format it

				 if (todoobj->overdue==nowdate &&todoobj->statue =="Not Done")  comboBox3->Items->Add(todoobj->title);
				 else  comboBox3->Items->Remove(todoobj->title);
			 
				 }catch(Exception^ex){
					 MessageBox::Show(ex->Message);
				 }

		 }

// when checkbox on edit panel changed
private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

			  if(checkBox1->Checked){
					 checkBox1->Text="Done"; 
			 checkBox1->ForeColor = System::Drawing::Color::Green; // change check box 2 colour
			  }

			  else{
					 checkBox1->Text="Not Done"; 
			checkBox1->ForeColor = System::Drawing::Color::Maroon; //change check box 2 colour
			  }
		 }

private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
		 }

// when combo box on todo today text changed
private: System::Void comboBox3_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 textBox8->Visible=true;
			 radioButton1->Visible=true;
			 radioButton2->Visible=true;

				
			   try{

			  MySqlConnection^ con= gcnew MySqlConnection( conobj->constr); 
			
			todoobj->title =comboBox3->Text;

			 MySqlCommand^cmd = gcnew MySqlCommand
				 ("Select * from todo.list where title = '"+todoobj->title+"';",con);
			
			 con->Open();
			  MySqlDataReader^dr;
			 dr = cmd->ExecuteReader();
			 dr->Read();

			  String ^ title= dr->GetString("title");
			  String^id = dr->GetString("id");
			  String^priority = dr->GetString("priority");
			  String^date = dr->GetString("overdue");
			  String ^statue= dr->GetString("statue");
			  String^detailes=dr->GetString("details");

			  con->Close();

			 textBox8->Text = "Task Title : " +title + " \r\n";
			   textBox8->Text += "\r\n";
			 textBox8->Text += "Task ID : " +id + "\r\n";
			   textBox8->Text += "\r\n";
			 textBox8->Text += "Task Priority : " +priority + "\r\n";
				textBox8->Text += "\r\n";
			 textBox8->Text += "Overdue Date : " +date + " \r\n";
				textBox8->Text += "\r\n";
			 textBox8->Text += "Task state : " +statue + " \r\n";
				 textBox8->Text += "\r\n";
			 textBox8->Text += "Task Details : " +detailes + " \r\n";
				textBox8->Text += "\r\n";

				if (statue == "Done"){
					radioButton1->Checked=true;
					}
				if (statue == "Not Done"){
					radioButton2->Checked=true;
					}

			}catch(Exception^ex){
			MessageBox::Show(ex->Message);
		 }
		 }

// when radio button 1 (done) on todo today panel changed
private: System::Void radioButton1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

			 if (radioButton1->Checked){
			  
				try{
			  MySqlConnection^ con= gcnew MySqlConnection( conobj->constr); 
			
			 todoobj->title =comboBox3->Text;

			 MySqlCommand^cmd=gcnew MySqlCommand
 ("update todo.list set statue= 'Done'   where title='"+todoobj->title+"'   ", con);
			
			 con->Open();
			  MySqlDataReader^dr;
			 dr = cmd->ExecuteReader();
			 dr->Read();

			 con ->Close();

			 comboBox3->Items->Remove(todoobj->title);

			  addsuccess^ openaddsuccess =gcnew addsuccess(); // show add success form 
			  openaddsuccess ->ShowDialog(); 

			 textBox8->Visible=false;
			 radioButton1->Visible=false;
			 radioButton2->Visible=false;
			 comboBox3->Text="                     Tasks ToDo Today";
				

			}catch(Exception^ex){
			MessageBox::Show(ex->Message);
		 }
			 }
		 }

 // when combo box on over due panel text changed
private: System::Void comboBox4_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 
			 textBox10->Visible =true ;
			   try{

			  MySqlConnection^ con= gcnew MySqlConnection( conobj->constr); 
			
			 todoobj->title =comboBox4->Text;

			 MySqlCommand^cmd = gcnew MySqlCommand
				 ("Select * from todo.list where title = '"+todoobj->title+"';",con);
			
			 con->Open();
			  MySqlDataReader^dr;
			 dr = cmd->ExecuteReader();
			 dr->Read();

			  String ^ title= dr->GetString("title");
			  String^id = dr->GetString("id");
			  String^priority = dr->GetString("priority");
			  String^date = dr->GetString("overdue");
			  String ^statue= dr->GetString("statue");
			  String^detailes=dr->GetString("details");

			  con->Close();

			 textBox10->Text = "Task Title : " +title + " \r\n";
			   textBox10->Text += "\r\n";
			 textBox10->Text += "Task ID : " +id + "\r\n";
			   textBox10->Text += "\r\n";
			 textBox10->Text += "Task Priority : " +priority + "\r\n";
				textBox10->Text += "\r\n";
			 textBox10->Text += "Overdue Date : " +date + " \r\n";
				textBox10->Text += "\r\n";
			 textBox10->Text += "Task state : " +statue + " \r\n";
				 textBox10->Text += "\r\n";
			 textBox10->Text += "Task Details : " +detailes + " \r\n";
				textBox10->Text += "\r\n";

			}catch(Exception^ex){
			MessageBox::Show(ex->Message);
		 }

		 }

// search panel (by name) radio button checked
private: System::Void radioButton5_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (radioButton5->Checked==true){
			 textBox13->Visible=true;   // name txt box
			 textBox12->Visible=false;  //id txt box
			 dateTimePicker3->Visible=false;
			 textBox13->Text="              Search by name";
			 textBox11->ResetText();
			 textBox11->Visible=false;
			 textBox14->Visible=false;

			 radioButton5->ForeColor = System::Drawing::Color::Green;
			 }
			 else
				 radioButton5->ForeColor = System::Drawing::Color::Maroon;
		 }

// search panel (by id) radio button checked
private: System::Void radioButton4_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (radioButton4->Checked==true){
			 textBox13->Visible=false;
			 textBox12->Visible=true;
			 dateTimePicker3->Visible=false;
			 textBox12->Text="              Search by id";
			 textBox11->ResetText();
			 textBox11->Visible=false;
			 textBox14->Visible=false;

			 radioButton4->ForeColor = System::Drawing::Color::Green;
			 }
			 else
				 radioButton4->ForeColor = System::Drawing::Color::Maroon;
			 
			 
		 }

// search panel (by date) radio button checked
private: System::Void radioButton3_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (radioButton3->Checked==true){
			 textBox13->Visible=false;
			 textBox12->Visible=false;
			 dateTimePicker3->Visible=true;
			 textBox11->ResetText();
			 textBox11->Visible=false;
			 textBox14->Visible=false;

			 radioButton3->ForeColor = System::Drawing::Color::Green;
			 }
			 else 
				 radioButton3->ForeColor = System::Drawing::Color::Maroon;

		 }

// when search button in search panel clicked
private: System::Void button18_Click(System::Object^  sender, System::EventArgs^  e) {
			 
			 if (radioButton3->Checked==true){
				 r3();
				 
					}

			 else if (radioButton4->Checked==true){
				 r4();
				 
					}

			 else  if (radioButton5->Checked==true){
				 r5();
				
					}
			 else if  (radioButton6->Checked==true){
				 r6();
			 }
			 else  MessageBox::Show("Invalid Input Entered");
			
		 }

// when by id text box on search panel clicked
private: System::Void textBox12_Click(System::Object^  sender, System::EventArgs^  e) {
			 textBox12->Clear();
		 }

// when by name  text box on search panel clicked
private: System::Void textBox13_Click(System::Object^  sender, System::EventArgs^  e) {
			 textBox13->Clear();
		 }

// when by priority  text box on search panel clicked
private: System::Void textBox14_Click(System::Object^  sender, System::EventArgs^  e) {
			 textBox14->Clear();
		 }

// search panel (by priority) radio button checked
private: System::Void radioButton6_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

				 if (radioButton6->Checked==true){

			 textBox13->Visible=false;
			 textBox12->Visible=false;
			 dateTimePicker3->Visible=false;
			 textBox11->ResetText();
			 textBox11->Visible=false;
			 textBox14->Visible=true;
			 textBox14->Text="             Search by Priority";
			 radioButton6->ForeColor = System::Drawing::Color::Green;
			 }

			 else 
				 radioButton6->ForeColor = System::Drawing::Color::Maroon;
		 }

// when list view 1 on todo list panel clicked
private: System::Void listView1_Click(System::Object^  sender, System::EventArgs^  e) {

			  panel36->Visible=true;

			if (listView1->SelectedItems->Count > 0)
			{
				for (int lcount = 0; lcount <= listView1->Items->Count - 1; lcount++)
				{
					if (listView1->Items[lcount]->Selected == true)
					{
						
						textBox15->Text = "Task Title : " +listView1->Items[lcount]->SubItems[1]->Text + " \r\n";
						textBox15->Text += "\r\n";
						textBox15->Text += "Task ID : " +listView1->Items[lcount]->SubItems[0]->Text + "\r\n";
						textBox15->Text += "\r\n";
						textBox15->Text += "Task Priority : " +listView1->Items[lcount]->SubItems[2]->Text + "\r\n";
						textBox15->Text += "\r\n";
						textBox15->Text += "Overdue Date : " +listView1->Items[lcount]->SubItems[3]->Text + " \r\n";
						textBox15->Text += "\r\n";
						textBox15->Text += "Task State : " +listView1->Items[lcount]->SubItems[5]->Text + " \r\n";
						textBox15->Text += "\r\n";
						textBox15->Text += "Task Details : " +listView1->Items[lcount]->SubItems[4]->Text + " \r\n";
						textBox15->Text += "\r\n";

						break;
					}
				}
			}
		 }

// when exit putton on details panel on todo list panel clicked
private: System::Void button20_Click(System::Object^  sender, System::EventArgs^  e) {
			 panel36->Visible=false;
		 }

// when list view 2 on Done panel clicked	 
private: System::Void listView2_Click(System::Object^  sender, System::EventArgs^  e) {

			  panel46->Visible=true;

			if (listView2->SelectedItems->Count > 0)
			{
				for (int lcount = 0; lcount <= listView2->Items->Count - 1; lcount++)
				{
					if (listView2->Items[lcount]->Selected == true)
					{
						
						textBox16->Text = "Task Title : " +listView2->Items[lcount]->SubItems[1]->Text + " \r\n";
						textBox16->Text += "\r\n";
						textBox16->Text += "Task ID : " +listView2->Items[lcount]->SubItems[0]->Text + "\r\n";
						textBox16->Text += "\r\n";
						textBox16->Text += "Task Priority : " +listView2->Items[lcount]->SubItems[2]->Text + "\r\n";
						textBox16->Text += "\r\n";
						textBox16->Text += "Overdue Date : " +listView2->Items[lcount]->SubItems[3]->Text + " \r\n";
						textBox16->Text += "\r\n";
						textBox16->Text += "Task State : " +listView2->Items[lcount]->SubItems[5]->Text + " \r\n";
						textBox16->Text += "\r\n";
						textBox16->Text += "Task Details : " +listView2->Items[lcount]->SubItems[4]->Text + " \r\n";
						textBox16->Text += "\r\n";
						break;
					}
				}
			}
		 }

// when exit putton on details panel on done panel clicked
private: System::Void button19_Click(System::Object^  sender, System::EventArgs^  e) {
			 panel46->Visible=false;
		 }

};

// finished :)
  // in 55 Days :")
	// 6-5-2018  1:20 AM 
}



	
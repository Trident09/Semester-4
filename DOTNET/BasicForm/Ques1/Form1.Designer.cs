namespace Ques1
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            First = new Label();
            Last = new Label();
            FNtext = new TextBox();
            LNtext = new TextBox();
            label3 = new Label();
            print = new Label();
            tableLayoutPanel1 = new TableLayoutPanel();
            clear = new Button();
            ok = new Button();
            tableLayoutPanel1.SuspendLayout();
            SuspendLayout();
            // 
            // First
            // 
            First.AutoSize = true;
            First.Font = new Font("Yu Gothic UI Light", 12F, FontStyle.Italic, GraphicsUnit.Point);
            First.Location = new Point(12, 69);
            First.Name = "First";
            First.Size = new Size(80, 21);
            First.TabIndex = 0;
            First.Text = "First Name";
            First.Click += label1_Click;
            // 
            // Last
            // 
            Last.AutoSize = true;
            Last.Font = new Font("Yu Gothic UI Light", 12F, FontStyle.Italic, GraphicsUnit.Point);
            Last.Location = new Point(12, 172);
            Last.Name = "Last";
            Last.Size = new Size(80, 21);
            Last.TabIndex = 1;
            Last.Text = "Last Name";
            // 
            // FNtext
            // 
            FNtext.Anchor = AnchorStyles.Top | AnchorStyles.Left | AnchorStyles.Right;
            FNtext.Location = new Point(12, 109);
            FNtext.Name = "FNtext";
            FNtext.Size = new Size(457, 23);
            FNtext.TabIndex = 2;
            // 
            // LNtext
            // 
            LNtext.Anchor = AnchorStyles.Top | AnchorStyles.Left | AnchorStyles.Right;
            LNtext.Location = new Point(12, 206);
            LNtext.Name = "LNtext";
            LNtext.Size = new Size(456, 23);
            LNtext.TabIndex = 3;
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Font = new Font("Yu Gothic UI Light", 12F, FontStyle.Italic, GraphicsUnit.Point);
            label3.Location = new Point(93, 9);
            label3.Name = "label3";
            label3.Size = new Size(222, 21);
            label3.TabIndex = 4;
            label3.Text = "Form Base Windows Application";
            // 
            // print
            // 
            print.AutoSize = true;
            print.Font = new Font("Yu Gothic UI Light", 12F, FontStyle.Italic, GraphicsUnit.Point);
            print.Location = new Point(12, 257);
            print.Name = "print";
            print.Size = new Size(50, 21);
            print.TabIndex = 5;
            print.Text = "Result";
            print.Click += label4_Click;
            // 
            // tableLayoutPanel1
            // 
            tableLayoutPanel1.Anchor = AnchorStyles.Bottom | AnchorStyles.Left | AnchorStyles.Right;
            tableLayoutPanel1.ColumnCount = 2;
            tableLayoutPanel1.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 50F));
            tableLayoutPanel1.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 50F));
            tableLayoutPanel1.Controls.Add(clear, 1, 0);
            tableLayoutPanel1.Controls.Add(ok, 0, 0);
            tableLayoutPanel1.Location = new Point(12, 359);
            tableLayoutPanel1.Name = "tableLayoutPanel1";
            tableLayoutPanel1.RowCount = 1;
            tableLayoutPanel1.RowStyles.Add(new RowStyle(SizeType.Percent, 100F));
            tableLayoutPanel1.RowStyles.Add(new RowStyle(SizeType.Absolute, 20F));
            tableLayoutPanel1.Size = new Size(457, 39);
            tableLayoutPanel1.TabIndex = 6;
            tableLayoutPanel1.Paint += tableLayoutPanel1_Paint;
            // 
            // clear
            // 
            clear.Location = new Point(231, 3);
            clear.Name = "clear";
            clear.Size = new Size(223, 33);
            clear.TabIndex = 1;
            clear.Text = "CLEAR";
            clear.UseVisualStyleBackColor = true;
            clear.Click += clear_Click;
            // 
            // ok
            // 
            ok.Location = new Point(3, 3);
            ok.Name = "ok";
            ok.Size = new Size(222, 33);
            ok.TabIndex = 0;
            ok.Text = "OK";
            ok.UseVisualStyleBackColor = true;
            ok.Click += ok_Click;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(480, 410);
            Controls.Add(tableLayoutPanel1);
            Controls.Add(print);
            Controls.Add(label3);
            Controls.Add(LNtext);
            Controls.Add(FNtext);
            Controls.Add(Last);
            Controls.Add(First);
            Name = "Form1";
            Text = "Welcome";
            Load += Form1_Load;
            tableLayoutPanel1.ResumeLayout(false);
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Label First;
        private Label Last;
        private TextBox FNtext;
        private TextBox LNtext;
        private Label label3;
        private Label print;
        private TableLayoutPanel tableLayoutPanel1;
        private Button clear;
        private Button ok;
    }
}
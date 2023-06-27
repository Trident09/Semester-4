namespace Ques1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void label4_Click(object sender, EventArgs e)
        {

        }

        private void tableLayoutPanel1_Paint(object sender, PaintEventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {
            print.Text = string.Empty;
        }

        private void ok_Click(object sender, EventArgs e)
        {
            String firstName = FNtext.Text;
            String lastName = LNtext.Text;
            print.Text = "Hello, " + firstName + " " + lastName;
        }

        private void clear_Click(object sender, EventArgs e)
        {
            FNtext.Text = null;
            LNtext.Text = null;
            print.Text = null;
        }
    }
}
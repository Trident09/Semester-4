using System;
using System.Windows.Forms;
using System.Data.SqlClient;
using System.Data;
using System.Configuration;
using System.Data.Common;

namespace ConnectedDemo
{
    public partial class Form1 : Form
    {

        SqlConnection con;
        SqlCommand cmd;
        SqlDataReader dr;

        public Form1()
        {
            InitializeComponent();
            con=new SqlConnection(ConfigurationManager.ConnectionStrings["DbConnection"].ConnectionString);
        }

        private void label4_Click(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {
    
        }

        private void btnSave_Click(object sender, EventArgs e)
        {
            try
            {
                string query = "insert into Product1 values(@name,@price,@company)";
                cmd = new SqlCommand(query, con);
                cmd.Parameters.AddWithValue("@name",txtname.Text);
                cmd.Parameters.AddWithValue("@price",Convert.ToInt32(txtprice.Text));
                cmd.Parameters.AddWithValue("@company", txtcompany.Text);
                con.Open();
                int result = cmd.ExecuteNonQuery();
                if (result >= 1)
                {
                    MessageBox.Show("Record Inserted");
                }
            }catch(Exception ex)
            {
                MessageBox.Show(ex.Message);    
            }
            finally { con.Close(); }
        }

        private void btnSearch_Click(object sender, EventArgs e)
        {
            try
            {

                string qry = "select * from Product1 where id=@id";
                cmd= new SqlCommand(qry, con);
                cmd.Parameters.AddWithValue("@id",Convert.ToInt32(txtid.Text));
                con.Open() ;
                dr=cmd.ExecuteReader();
                if(dr.HasRows)
                {
                    while (dr.Read())
                    {
                        txtname.Text = dr["name"].ToString();
                        txtcompany.Text = dr["company"].ToString();
                        txtprice.Text = dr["price"].ToString() ;
                    }
                }
                else
                {
                    MessageBox.Show("Record not found");
                }


            }catch(Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
            finally { con.Close(); }
        }

        private void btnUpdate_Click(object sender, EventArgs e)
        {
            try
            {
                string query = "update Product1 set name=@name,company=@company,price=@price where id=@id";
                cmd= new SqlCommand(query, con);
                cmd.Parameters.AddWithValue("@name", txtname.Text);
                cmd.Parameters.AddWithValue("@company", txtcompany.Text);
                cmd.Parameters.AddWithValue("@price", Convert.ToInt32(txtprice.Text));
                cmd.Parameters.AddWithValue("@id", Convert.ToInt32(txtid.Text));
                con.Open() ;

                int result=cmd.ExecuteNonQuery();
                if(result>=1)
                {
                    MessageBox.Show("Record Updated");

                }

            }
            catch (Exception ex )
            {
                MessageBox.Show(ex.Message);
            }
            finally { con.Close(); }
        }

        private void btnDelete_Click(object sender, EventArgs e)
        {
            try
            {
                string query = "delete from Product1 where id=@id";
                cmd = new SqlCommand(query, con);
                cmd.Parameters.AddWithValue("@id", Convert.ToInt32(txtid.Text));
                con.Open();
                int result = cmd.ExecuteNonQuery();
                if (result >= 1)
                {
                    MessageBox.Show("Record deleted..");
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
            finally
            {
                con.Close();
            }

        }

        private void btnshowproducts_Click(object sender, EventArgs e)
        {
            try
            {
                string qry = "select * from Product1";
                cmd = new SqlCommand(qry, con);
                con.Open();
                dr = cmd.ExecuteReader();
                if (dr.HasRows)
                {
                    DataTable dataTable = new DataTable();
                    dataTable.Load(dr);
                    dataGridView1.DataSource = dataTable;
                }
                else
                {
                    MessageBox.Show("Record not found");
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
            finally
            {
                con.Close();
            }

        }

        private void label2_Click(object sender, EventArgs e)
        {

        }
    }
}

using System;
using System.Data;
using System.Data.SqlClient;

namespace ConsoleApp
{
    class Program
    {
        static void Main(string[] args)
        {
            string connectionString = "Data Source=(LocalDB)\\MSSQLLocalDB;AttachDbFilename=\"C:\\Users\\Student 93\\Documents\\Rupamdb.mdf\";Integrated Security=True;Connect Timeout=30";     // Replace with your actual connection string

            using (SqlConnection connection = new SqlConnection(connectionString))
            {
                connection.Open();

                // Main program loop
                while (true)
                {
                    Console.WriteLine("Select an option:");
                    Console.WriteLine("1. Add a new record");
                    Console.WriteLine("2. Search for a record");
                    Console.WriteLine("3. Edit a record");
                    Console.WriteLine("4. Delete a record");
                    Console.WriteLine("5. Display all records");
                    Console.WriteLine("6. Exit");

                    string choice = Console.ReadLine();

                    switch (choice)
                    {
                        case "1":
                            Console.WriteLine("Enter the first name:");
                            string firstName = Console.ReadLine();
                            Console.WriteLine("Enter the last name:");
                            string lastName = Console.ReadLine();
                            AddRecord(connection, firstName, lastName);
                            break;

                        case "2":
                            Console.WriteLine("Enter the first name to search:");
                            string searchFirstName = Console.ReadLine();
                            Console.WriteLine("Enter the last name to search:");
                            string searchLastName = Console.ReadLine();
                            DataTable searchResults = SearchRecords(connection, searchFirstName, searchLastName);
                            DisplayRecords(searchResults);
                            break;

                        case "3":
                            Console.WriteLine("Enter the record ID to edit:");
                            int editId = int.Parse(Console.ReadLine());
                            Console.WriteLine("Enter the new first name:");
                            string newFirstName = Console.ReadLine();
                            Console.WriteLine("Enter the new last name:");
                            string newLastName = Console.ReadLine();
                            EditRecord(connection, editId, newFirstName, newLastName);
                            break;

                        case "4":
                            Console.WriteLine("Enter the record ID to delete:");
                            int deleteId = int.Parse(Console.ReadLine());
                            DeleteRecord(connection, deleteId);
                            break;

                        case "5":
                            DataTable allRecords = GetAllRecords(connection);
                            DisplayRecords(allRecords);
                            break;

                        case "6":
                            // Exit the program
                            return;

                        default:
                            Console.WriteLine("Invalid choice. Please try again.");
                            break;
                    }

                    Console.WriteLine();
                }
            }
        }

        static void AddRecord(SqlConnection connection, string firstName, string lastName)
        {
            string query = "INSERT INTO Employees (FirstName, LastName) VALUES (@FirstName, @LastName)";

            using (SqlCommand command = new SqlCommand(query, connection))
            {
                command.Parameters.AddWithValue("@FirstName", firstName);
                command.Parameters.AddWithValue("@LastName", lastName);

                int rowsAffected = command.ExecuteNonQuery();

                if (rowsAffected > 0)
                {
                    Console.WriteLine("Record added successfully.");
                }
                else
                {
                    Console.WriteLine("Failed to add record.");
                }
            }
        }

        static DataTable SearchRecords(SqlConnection connection, string firstName, string lastName)
        {
            string query = "SELECT * FROM Employees WHERE FirstName = @FirstName AND LastName = @LastName";

            using (SqlCommand command = new SqlCommand(query, connection))
            {
                command.Parameters.AddWithValue("@FirstName", firstName);
                command.Parameters.AddWithValue("@LastName", lastName);

                DataTable dataTable = new DataTable();
                using (SqlDataAdapter dataAdapter = new SqlDataAdapter(command))
                {
                    dataAdapter.Fill(dataTable);
                }

                return dataTable;
            }
        }

        static void EditRecord(SqlConnection connection, int recordId, string newFirstName, string newLastName)
        {
            string query = "UPDATE Employees SET FirstName = @FirstName, LastName = @LastName WHERE EmployeeID = @EmployeeID";

            using (SqlCommand command = new SqlCommand(query, connection))
            {
                command.Parameters.AddWithValue("@FirstName", newFirstName);
                command.Parameters.AddWithValue("@LastName", newLastName);
                command.Parameters.AddWithValue("@EmployeeID", recordId);

                int rowsAffected = command.ExecuteNonQuery();

                if (rowsAffected > 0)
                {
                    Console.WriteLine("Record updated successfully.");
                }
                else
                {
                    Console.WriteLine("Failed to update record.");
                }
            }
        }

        static void DeleteRecord(SqlConnection connection, int recordId)
        {
            string query = "DELETE FROM Employees WHERE EmployeeID = @EmployeeID";

            using (SqlCommand command = new SqlCommand(query, connection))
            {
                command.Parameters.AddWithValue("@EmployeeID", recordId);

                int rowsAffected = command.ExecuteNonQuery();

                if (rowsAffected > 0)
                {
                    Console.WriteLine("Record deleted successfully.");
                }
                else
                {
                    Console.WriteLine("Failed to delete record.");
                }
            }
        }

        static DataTable GetAllRecords(SqlConnection connection)
        {
            string query = "SELECT * FROM Employees";

            using (SqlCommand command = new SqlCommand(query, connection))
            {
                DataTable dataTable = new DataTable();
                using (SqlDataAdapter dataAdapter = new SqlDataAdapter(command))
                {
                    dataAdapter.Fill(dataTable);
                }

                return dataTable;
            }
        }

        static void DisplayRecords(DataTable dataTable)
        {
            if (dataTable.Rows.Count > 0)
            {
                foreach (DataRow row in dataTable.Rows)
                {
                    Console.WriteLine($"ID: {row["EmployeeID"]}, Name: {row["FirstName"]} {row["LastName"]}");
                }
            }
            else
            {
                Console.WriteLine("No records found.");
            }
        }
    }
}
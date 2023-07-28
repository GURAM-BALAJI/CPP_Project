#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

// Function to split a comma-separated string into a vector of strings
std::vector<std::string> splitCSV(const std::string &line)
{
    std::vector<std::string> fields;
    std::stringstream ss(line);
    std::string field;
    while (std::getline(ss, field, ','))
    {
        fields.push_back(field);
    }
    return fields;
}
// Function to display all students from student.csv file
void viewStudents()
{
    std::ifstream studentFile("student.csv");
    if (!studentFile)
    {
        std::cout << "Error opening student.csv file.\n";
        return;
    }

    std::string line;
    std::getline(studentFile, line); // Read and discard the column headers

    std::cout << "\n--- List of Students ---\n";
    while (std::getline(studentFile, line))
    {
        std::vector<std::string> studentFields = splitCSV(line);
        std::cout << "Student ID: " << studentFields[0] << '\n';
        std::cout << "Name: " << studentFields[1] << '\n';
        std::cout << "Phone: " << studentFields[2] << '\n';
        std::cout << "Username: " << studentFields[4] << '\n';
        std::cout << "-------------------------\n";
    }

    studentFile.close();
}

void addNewStudent()
{
    std::ofstream studentFile("student.csv", std::ios::app); // Open file in append mode
    if (!studentFile)
    {
        std::cout << "Error opening student.csv file for writing.\n";
        return;
    }

    std::string studentID, studentName, studentPhone, studentUsername, studentPassword, studentRouteID;
    std::cout << "Enter Student ID: ";
    std::cin >> studentID;
    std::cout << "Enter Student Name: ";
    std::cin.ignore();
    std::getline(std::cin, studentName);
    std::cout << "Enter Student Phone: ";
    std::cin >> studentPhone;
    std::cout << "Enter Student Username: ";
    std::cin >> studentUsername;
    std::cout << "Enter Student Password: ";
    std::cin >> studentPassword;
    std::cout << "Enter Student Route ID: ";
    std::cin >> studentRouteID;

    studentFile << studentID << "," << studentName << "," << studentPhone << "," << studentRouteID
                << "," << studentUsername << "," << studentPassword << "\n";

    studentFile.close();

    std::cout << "New student added successfully.\n";
}

// Function to edit a student in student.csv file
void editStudent()
{
    std::string studentID;
    std::cout << "Enter the Student ID to edit: ";
    std::cin >> studentID;

    std::ifstream studentFile("student.csv");
    if (!studentFile)
    {
        std::cout << "Error opening student.csv file.\n";
        return;
    }

    std::ofstream tempFile("temp.csv");
    if (!tempFile)
    {
        std::cout << "Error opening temp.csv file.\n";
        return;
    }

    std::string line;
    bool found = false;
    while (std::getline(studentFile, line))
    {
        std::vector<std::string> studentFields = splitCSV(line);
        if (studentFields[0] == studentID)
        {
            std::string studentName, studentPhone, studentUsername, studentPassword, studentRouteID;
            std::cout << "Enter Student Name: ";
            std::cin.ignore();
            std::getline(std::cin, studentName);
            std::cout << "Enter Student Phone: ";
            std::cin >> studentPhone;
            std::cout << "Enter Student Username: ";
            std::cin >> studentUsername;
            std::cout << "Enter Student Password: ";
            std::cin >> studentPassword;
            std::cout << "Enter Student Route ID: ";
            std::cin >> studentRouteID;

            tempFile << studentID << "," << studentName << "," << studentPhone << "," << studentRouteID
                     << "," << studentUsername << "," << studentPassword << "\n";
            found = true;
        }
        else
        {
            tempFile << line << "\n";
        }
    }

    studentFile.close();
    tempFile.close();

    if (!found)
    {
        std::cout << "Student with ID " << studentID << " not found.\n";
        return;
    }

    // Remove the original file and rename the temp file to student.csv
    std::remove("student.csv");
    std::rename("temp.csv", "student.csv");

    std::cout << "Student updated successfully.\n";
}

// Function to delete a student from student.csv file
void deleteStudent()
{
    std::string studentID;
    std::cout << "Enter the Student ID to delete: ";
    std::cin >> studentID;

    std::ifstream studentFile("student.csv");
    if (!studentFile)
    {
        std::cout << "Error opening student.csv file.\n";
        return;
    }

    std::ofstream tempFile("temp.csv");
    if (!tempFile)
    {
        std::cout << "Error opening temp.csv file.\n";
        return;
    }

    std::string line;
    bool found = false;
    while (std::getline(studentFile, line))
    {
        std::vector<std::string> studentFields = splitCSV(line);
        if (studentFields[0] != studentID)
        {
            tempFile << line << "\n";
        }
        else
        {
            found = true;
        }
    }

    studentFile.close();
    tempFile.close();

    if (!found)
    {
        std::cout << "Student with ID " << studentID << " not found.\n";
        return;
    }

    // Remove the original file and rename the temp file to student.csv
    std::remove("student.csv");
    std::rename("temp.csv", "student.csv");

    std::cout << "Student deleted successfully.\n";
}

// Function to delete a driver from driver.csv file
void deleteDriver()
{
    std::string driverID;
    std::cout << "Enter the Driver ID to delete: ";
    std::cin >> driverID;

    std::ifstream driverFile("driver.csv");
    if (!driverFile)
    {
        std::cout << "Error opening driver.csv file.\n";
        return;
    }

    std::ofstream tempFile("temp.csv");
    if (!tempFile)
    {
        std::cout << "Error opening temp.csv file.\n";
        return;
    }

    std::string line;
    bool found = false;
    while (std::getline(driverFile, line))
    {
        std::vector<std::string> driverFields = splitCSV(line);
        if (driverFields[0] != driverID)
        {
            tempFile << line << "\n";
        }
        else
        {
            found = true;
        }
    }

    driverFile.close();
    tempFile.close();

    if (!found)
    {
        std::cout << "Driver with ID " << driverID << " not found.\n";
        return;
    }

    // Remove the original file and rename the temp file to driver.csv
    std::remove("driver.csv");
    std::rename("temp.csv", "driver.csv");

    std::cout << "Driver deleted successfully.\n";
}

// Function to edit a driver in driver.csv file
void editDriver()
{
    std::string driverID;
    std::cout << "Enter the Driver ID to edit: ";
    std::cin >> driverID;

    std::ifstream driverFile("driver.csv");
    if (!driverFile)
    {
        std::cout << "Error opening driver.csv file.\n";
        return;
    }

    std::ofstream tempFile("temp.csv");
    if (!tempFile)
    {
        std::cout << "Error opening temp.csv file.\n";
        return;
    }

    std::string line;
    bool found = false;
    while (std::getline(driverFile, line))
    {
        std::vector<std::string> driverFields = splitCSV(line);
        if (driverFields[0] == driverID)
        {
            found = true;
            std::string driverName, driverPhone, driverUsername, driverPassword, driverBusID;
            std::cout << "Enter new Driver Name: ";
            std::cin.ignore();
            std::getline(std::cin, driverName);
            std::cout << "Enter new Driver Phone: ";
            std::cin >> driverPhone;
            std::cout << "Enter new Driver Username: ";
            std::cin >> driverUsername;
            std::cout << "Enter new Driver Password: ";
            std::cin >> driverPassword;
            std::cout << "Enter new Driver Bus ID: ";
            std::cin >> driverBusID;

            tempFile << driverFields[0] << "," << driverName << "," << driverPhone << ","
                     << driverUsername << "," << driverPassword << "," << driverBusID << "\n";
        }
        else
        {
            tempFile << line << "\n";
        }
    }

    driverFile.close();
    tempFile.close();

    if (!found)
    {
        std::cout << "Driver with ID " << driverID << " not found.\n";
        return;
    }

    // Remove the original file and rename the temp file to driver.csv
    std::remove("driver.csv");
    std::rename("temp.csv", "driver.csv");

    std::cout << "Driver updated successfully.\n";
}

void addNewDriver()
{
    std::ofstream driverFile("driver.csv", std::ios::app);
    if (!driverFile)
    {
        std::cout << "Error opening driver.csv file for writing.\n";
        return;
    }

    std::string driverID, driverName, driverPhone, driverUsername, driverPassword, driverBusID;
    std::cout << "Enter Driver ID: ";
    std::cin >> driverID;
    std::cout << "Enter Driver Name: ";
    std::cin.ignore();
    std::getline(std::cin, driverName);
    std::cout << "Enter Driver Phone: ";
    std::cin >> driverPhone;
    std::cout << "Enter Driver Username: ";
    std::cin >> driverUsername;
    std::cout << "Enter Driver Password: ";
    std::cin >> driverPassword;
    std::cout << "Enter Driver Bus ID: ";
    std::cin >> driverBusID;

    driverFile << driverID << "," << driverName << "," << driverPhone << ","
               << driverUsername << "," << driverPassword << "," << driverBusID << "\n";

    std::cout << "Driver added successfully.\n";
}

// Function to display all drivers from driver.csv file
void viewDrivers()
{
    std::ifstream driverFile("driver.csv");
    if (!driverFile)
    {
        std::cout << "Error opening driver.csv file.\n";
        return;
    }

    std::string line;
    std::getline(driverFile, line); // Read and discard the column headers

    std::cout << "\n--- List of Drivers ---\n";
    while (std::getline(driverFile, line))
    {
        std::vector<std::string> driverFields = splitCSV(line);
        std::cout << "Driver ID: " << driverFields[0] << '\n';
        std::cout << "Name: " << driverFields[1] << '\n';
        std::cout << "Phone: " << driverFields[2] << '\n';
        std::cout << "Username: " << driverFields[3] << '\n';
        std::cout << "Bus ID: " << driverFields[5] << '\n';
        std::cout << "-------------------------\n";
    }

    driverFile.close();
}

// Function to read the CSV data and return a vector of lines
std::vector<std::string> readCSV(const std::string &filename)
{
    std::vector<std::string> lines;
    std::ifstream file(filename);
    std::string line;

    if (file.is_open())
    {
        while (getline(file, line))
        {
            lines.push_back(line);
        }
        file.close();
    }

    return lines;
}

// Function to write the CSV data
void writeCSV(const std::string &filename, const std::vector<std::string> &lines)
{
    std::ofstream file(filename);
    for (const std::string &line : lines)
    {
        file << line << "\n";
    }
    file.close();
}

// Function to check if a value exists in a CSV file
bool isValueExistsInCSV(const std::string &filename, const std::string &value)
{
    std::vector<std::string> lines = readCSV(filename);
    for (const std::string &line : lines)
    {
        std::vector<std::string> fields = splitCSV(line);
        if (std::find(fields.begin(), fields.end(), value) != fields.end())
        {
            return true;
        }
    }
    return false;
}

// Function to handle admin login
bool adminLogin()
{
    std::string username, password;
    std::cout << "Enter Admin Username: ";
    std::cin >> username;
    std::cout << "Enter Admin Password: ";
    std::cin >> password;

    // Check if admin credentials are correct
    std::vector<std::string> adminData = readCSV("admin.csv");
    for (const std::string &line : adminData)
    {
        std::vector<std::string> fields = splitCSV(line);
        if (fields[1] == username && fields[2] == password)
        {
            return true;
        }
    }

    return false;
}

// Function to join CSV fields into a single string (Moved to global scope)
std::string joinCSV(const std::vector<std::string> &fields)
{
    std::string line;
    for (size_t i = 0; i < fields.size(); ++i)
    {
        line += fields[i];
        if (i < fields.size() - 1)
        {
            line += ",";
        }
    }
    return line;
}

// Function to display all admins from admin.csv file
void viewAdmins()
{
    std::ifstream adminFile("admin.csv");
    if (!adminFile)
    {
        std::cout << "Error opening admin.csv file.\n";
        return;
    }

    std::string line;
    std::getline(adminFile, line); // Read and discard the column headers

    std::cout << "\n--- List of Admins ---\n";
    while (std::getline(adminFile, line))
    {
        std::vector<std::string> adminFields = splitCSV(line);
        std::cout << "Admin ID: " << adminFields[0] << '\n';
        std::cout << "Username: " << adminFields[1] << '\n';
        std::cout << "-------------------------\n";
    }

    adminFile.close();
}

// Function to add a new admin to admin.csv file
void addNewAdmin()
{
    std::ofstream adminFile("admin.csv", std::ios::app); // Open file in append mode
    if (!adminFile)
    {
        std::cout << "Error opening admin.csv file for writing.\n";
        return;
    }

    std::string adminID, adminUsername, adminPassword;
    std::cout << "Enter Admin ID: ";
    std::cin >> adminID;
    std::cout << "Enter Admin Username: ";
    std::cin >> adminUsername;
    std::cout << "Enter Admin Password: ";
    std::cin >> adminPassword;

    adminFile << adminID << "," << adminUsername << "," << adminPassword << "\n";

    adminFile.close();

    std::cout << "New admin added successfully.\n";
}

// Function to edit an admin in admin.csv file
void editAdmin()
{
    std::string adminID;
    std::cout << "Enter the Admin ID to edit: ";
    std::cin >> adminID;

    std::ifstream adminFile("admin.csv");
    if (!adminFile)
    {
        std::cout << "Error opening admin.csv file.\n";
        return;
    }

    std::ofstream tempFile("temp.csv");
    if (!tempFile)
    {
        std::cout << "Error opening temp.csv file.\n";
        return;
    }

    std::string line;
    bool found = false;
    while (std::getline(adminFile, line))
    {
        std::vector<std::string> adminFields = splitCSV(line);
        if (adminFields[0] == adminID)
        {
            std::string adminUsername, adminPassword;
            std::cout << "Enter Admin Username: ";
            std::cin >> adminUsername;
            std::cout << "Enter Admin Password: ";
            std::cin >> adminPassword;

            tempFile << adminID << "," << adminUsername << "," << adminPassword << "\n";
            found = true;
        }
        else
        {
            tempFile << line << "\n";
        }
    }

    adminFile.close();
    tempFile.close();

    if (!found)
    {
        std::cout << "Admin with ID " << adminID << " not found.\n";
        return;
    }

    // Remove the original file and rename the temp file to admin.csv
    std::remove("admin.csv");
    std::rename("temp.csv", "admin.csv");

    std::cout << "Admin updated successfully.\n";
}

// Function to delete an admin from admin.csv file
void deleteAdmin()
{
    std::string adminID;
    std::cout << "Enter the Admin ID to delete: ";
    std::cin >> adminID;

    std::ifstream adminFile("admin.csv");
    if (!adminFile)
    {
        std::cout << "Error opening admin.csv file.\n";
        return;
    }

    std::ofstream tempFile("temp.csv");
    if (!tempFile)
    {
        std::cout << "Error opening temp.csv file.\n";
        return;
    }

    std::string line;
    bool found = false;
    while (std::getline(adminFile, line))
    {
        std::vector<std::string> adminFields = splitCSV(line);
        if (adminFields[0] != adminID)
        {
            tempFile << line << "\n";
        }
        else
        {
            found = true;
        }
    }

    adminFile.close();
    tempFile.close();

    if (!found)
    {
        std::cout << "Admin with ID " << adminID << " not found.\n";
        return;
    }

    // Remove the original file and rename the temp file to admin.csv
    std::remove("admin.csv");
    std::rename("temp.csv", "admin.csv");

    std::cout << "Admin deleted successfully.\n";
}
// Function to display all routes from routes.csv file
void viewRoutes()
{
    std::ifstream routesFile("routes.csv");
    if (!routesFile)
    {
        std::cout << "Error opening routes.csv file.\n";
        return;
    }

    std::string line;
    std::getline(routesFile, line); // Read and discard the column headers

    std::cout << "\n--- List of Routes ---\n";
    while (std::getline(routesFile, line))
    {
        std::vector<std::string> routeFields = splitCSV(line);
        std::cout << "Route ID: " << routeFields[0] << '\n';
        std::cout << "Route Name: " << routeFields[1] << '\n';
        std::cout << "-------------------------\n";
    }

    routesFile.close();
}

// Function to add a new route to routes.csv file
void addNewRoute()
{
    std::ofstream routesFile("routes.csv", std::ios::app); // Open file in append mode
    if (!routesFile)
    {
        std::cout << "Error opening routes.csv file for writing.\n";
        return;
    }

    std::string routeID, routeName;
    std::cout << "Enter Route ID: ";
    std::cin >> routeID;
    std::cout << "Enter Route Name: ";
    std::cin.ignore();
    std::getline(std::cin, routeName);

    routesFile << routeID << "," << routeName << "\n";

    routesFile.close();

    std::cout << "New route added successfully.\n";
}

// Function to edit a route in routes.csv file
void editRoute()
{
    std::string routeID;
    std::cout << "Enter the Route ID to edit: ";
    std::cin >> routeID;

    std::ifstream routesFile("routes.csv");
    if (!routesFile)
    {
        std::cout << "Error opening routes.csv file.\n";
        return;
    }

    std::ofstream tempFile("temp.csv");
    if (!tempFile)
    {
        std::cout << "Error opening temp.csv file.\n";
        return;
    }

    std::string line;
    bool found = false;
    while (std::getline(routesFile, line))
    {
        std::vector<std::string> routeFields = splitCSV(line);
        if (routeFields[0] == routeID)
        {
            std::string routeName;
            std::cout << "Enter Route Name: ";
            std::cin.ignore();
            std::getline(std::cin, routeName);

            tempFile << routeID << "," << routeName << "\n";
            found = true;
        }
        else
        {
            tempFile << line << "\n";
        }
    }

    routesFile.close();
    tempFile.close();

    if (!found)
    {
        std::cout << "Route with ID " << routeID << " not found.\n";
        return;
    }

    // Remove the original file and rename the temp file to routes.csv
    std::remove("routes.csv");
    std::rename("temp.csv", "routes.csv");

    std::cout << "Route updated successfully.\n";
}

// Function to delete a route from routes.csv file
void deleteRoute()
{
    std::string routeID;
    std::cout << "Enter the Route ID to delete: ";
    std::cin >> routeID;

    std::ifstream routesFile("routes.csv");
    if (!routesFile)
    {
        std::cout << "Error opening routes.csv file.\n";
        return;
    }

    std::ofstream tempFile("temp.csv");
    if (!tempFile)
    {
        std::cout << "Error opening temp.csv file.\n";
        return;
    }

    std::string line;
    bool found = false;
    while (std::getline(routesFile, line))
    {
        std::vector<std::string> routeFields = splitCSV(line);
        if (routeFields[0] != routeID)
        {
            tempFile << line << "\n";
        }
        else
        {
            found = true;
        }
    }

    routesFile.close();
    tempFile.close();

    if (!found)
    {
        std::cout << "Route with ID " << routeID << " not found.\n";
        return;
    }

    // Remove the original file and rename the temp file to routes.csv
    std::remove("routes.csv");
    std::rename("temp.csv", "routes.csv");

    std::cout << "Route deleted successfully.\n";
}

// Function to display all stops from stops.csv file
void viewStops()
{
    std::ifstream stopsFile("stops.csv");
    if (!stopsFile)
    {
        std::cout << "Error opening stops.csv file.\n";
        return;
    }

    std::string line;
    std::getline(stopsFile, line); // Read and discard the column headers

    std::cout << "\n--- List of Stops ---\n";
    while (std::getline(stopsFile, line))
    {
        std::vector<std::string> stopsFields = splitCSV(line);
        std::cout << "Stop ID: " << stopsFields[0] << '\n';
        std::cout << "Stop Name: " << stopsFields[1] << '\n';
        std::cout << "Route ID: " << stopsFields[2] << '\n';
        std::cout << "-------------------------\n";
    }

    stopsFile.close();
}

// Function to add a new stop to stops.csv file
void addNewStop()
{
    std::ofstream stopsFile("stops.csv", std::ios::app); // Open file in append mode
    if (!stopsFile)
    {
        std::cout << "Error opening stops.csv file for writing.\n";
        return;
    }

    std::string stopID, stopName, routeID;
    std::cout << "Enter Stop ID: ";
    std::cin >> stopID;
    std::cout << "Enter Stop Name: ";
    std::cin.ignore();
    std::getline(std::cin, stopName);
    std::cout << "Enter Route ID: ";
    std::cin >> routeID;

    // Check if the route exists in routes.csv
    bool routeExists = false;
    std::ifstream routesFile("routes.csv");
    if (routesFile)
    {
        std::string line;
        std::getline(routesFile, line); // Read and discard the column headers
        while (std::getline(routesFile, line))
        {
            std::vector<std::string> routeFields = splitCSV(line);
            if (routeFields[0] == routeID)
            {
                routeExists = true;
                break;
            }
        }
    }
    else
    {
        std::cout << "Error opening routes.csv file.\n";
        stopsFile.close();
        return;
    }

    if (!routeExists)
    {
        std::cout << "Route with ID " << routeID << " not found. Cannot add stop.\n";
        stopsFile.close();
        return;
    }

    stopsFile << stopID << "," << stopName << "," << routeID << "\n";

    stopsFile.close();

    std::cout << "New stop added successfully.\n";
}

// Function to edit a stop in stops.csv file
void editStop()
{
    std::string stopID;
    std::cout << "Enter the Stop ID to edit: ";
    std::cin >> stopID;

    std::ifstream stopsFile("stops.csv");
    if (!stopsFile)
    {
        std::cout << "Error opening stops.csv file.\n";
        return;
    }

    std::ofstream tempFile("temp.csv");
    if (!tempFile)
    {
        std::cout << "Error opening temp.csv file.\n";
        return;
    }

    std::string line;
    bool found = false;
    while (std::getline(stopsFile, line))
    {
        std::vector<std::string> stopsFields = splitCSV(line);
        if (stopsFields[0] == stopID)
        {
            std::string stopName, routeID;
            std::cout << "Enter Stop Name: ";
            std::cin.ignore();
            std::getline(std::cin, stopName);
            std::cout << "Enter Route ID: ";
            std::cin >> routeID;

            // Check if the route exists in routes.csv
            bool routeExists = false;
            std::ifstream routesFile("routes.csv");
            if (routesFile)
            {
                std::string rline;
                std::getline(routesFile, rline); // Read and discard the column headers
                while (std::getline(routesFile, rline))
                {
                    std::vector<std::string> routeFields = splitCSV(rline);
                    if (routeFields[0] == routeID)
                    {
                        routeExists = true;
                        break;
                    }
                }
            }
            else
            {
                std::cout << "Error opening routes.csv file.\n";
                stopsFile.close();
                tempFile.close();
                return;
            }

            if (!routeExists)
            {
                std::cout << "Route with ID " << routeID << " not found. Cannot update stop.\n";
                stopsFile.close();
                tempFile.close();
                return;
            }

            tempFile << stopID << "," << stopName << "," << routeID << "\n";
            found = true;
        }
        else
        {
            tempFile << line << "\n";
        }
    }

    stopsFile.close();
    tempFile.close();

    if (!found)
    {
        std::cout << "Stop with ID " << stopID << " not found.\n";
        return;
    }

    // Remove the original file and rename the temp file to stops.csv
    std::remove("stops.csv");
    std::rename("temp.csv", "stops.csv");

    std::cout << "Stop updated successfully.\n";
}

// Function to delete a stop from stops.csv file
void deleteStop()
{
    std::string stopID;
    std::cout << "Enter the Stop ID to delete: ";
    std::cin >> stopID;

    std::ifstream stopsFile("stops.csv");
    if (!stopsFile)
    {
        std::cout << "Error opening stops.csv file.\n";
        return;
    }

    std::ofstream tempFile("temp.csv");
    if (!tempFile)
    {
        std::cout << "Error opening temp.csv file.\n";
        return;
    }

    std::string line;
    bool found = false;
    while (std::getline(stopsFile, line))
    {
        std::vector<std::string> stopsFields = splitCSV(line);
        if (stopsFields[0] != stopID)
        {
            tempFile << line << "\n";
        }
        else
        {
            found = true;
        }
    }

    stopsFile.close();
    tempFile.close();

    if (!found)
    {
        std::cout << "Stop with ID " << stopID << " not found.\n";
        return;
    }

    // Remove the original file and rename the temp file to stops.csv
    std::remove("stops.csv");
    std::rename("temp.csv", "stops.csv");

    std::cout << "Stop deleted successfully.\n";
}

// Function to display all available stops for a given route_id
void displayAvailableStopsForRoute(const std::string &routeID)
{
    std::ifstream stopsFile("stops.csv");
    if (!stopsFile)
    {
        std::cout << "Error opening stops.csv file.\n";
        return;
    }

    std::string line;
    while (std::getline(stopsFile, line))
    {
        std::vector<std::string> stopFields = splitCSV(line);
        if (stopFields.size() >= 3 && stopFields[2] == routeID)
        {
            std::cout << "Stop ID: " << stopFields[0] << ", Stop Name: " << stopFields[1] << "\n";
        }
    }

    stopsFile.close();
}

// Function to check if a student ID exists in the pick.csv file
bool isStudentIDExistsInPick(const std::string &studentID)
{
    std::ifstream pickFile("pick.csv");
    if (!pickFile)
    {
        return false;
    }

    std::string line;
    while (std::getline(pickFile, line))
    {
        std::vector<std::string> pickFields = splitCSV(line);
        if (pickFields.size() >= 1 && pickFields[0] == studentID)
        {
            return true;
        }
    }

    pickFile.close();
    return false;
}

// Function to update the pick.csv file with new or existing pick-up information
void updatePickCSV(const std::string &studentID, const std::string &stopID, const std::string &routeID)
{
    std::ifstream pickFile("pick.csv");
    if (!pickFile)
    {
        std::cout << "Error opening pick.csv file.\n";
        return;
    }

    std::string line;
    std::vector<std::string> pickData;
    bool foundStudentID = false;

    while (std::getline(pickFile, line))
    {
        std::vector<std::string> pickFields = splitCSV(line);
        if (pickFields.size() >= 1 && pickFields[0] == studentID)
        {
            line = studentID + "," + stopID + "," + routeID;
            foundStudentID = true;
        }
        pickData.push_back(line);
    }

    pickFile.close();

    if (!foundStudentID)
    {
        // If the student ID was not found, append a new row to the data
        std::string newLine = studentID + "," + stopID + "," + routeID;
        pickData.push_back(newLine);
    }

    std::ofstream pickFileOut("pick.csv");
    if (!pickFileOut)
    {
        std::cout << "Error opening pick.csv file.\n";
        return;
    }

    // Write back the modified pick-up data
    for (const auto &line : pickData)
    {
        pickFileOut << line << "\n";
    }

    pickFileOut.close();
}
void pickUpFunctionality(const std::string &studentID, const std::string &routeID)
{
    std::cout << "Available Pick-up Stops for your route:\n";
    displayAvailableStopsForRoute(routeID);

    std::string stopID;
    std::cout << "Enter the Stop ID where you want to pick up: ";
    std::cin >> stopID;

    // Check if the student ID exists in pick.csv
    bool studentExists = isStudentIDExistsInPick(studentID);

    // Update the pick.csv file with new or existing pick-up information
    updatePickCSV(studentID, stopID, routeID);

    if (studentExists)
    {
        std::cout << "Pick-up information updated successfully!\n";
    }
    else
    {
        std::cout << "Pick-up information saved successfully!\n";
    }
}

// Function to check if a student ID exists in the drop.csv file
bool isStudentIDExistsInDrop(const std::string &studentID)
{
    std::ifstream dropFile("drop.csv");
    if (!dropFile)
    {
        return false;
    }

    std::string line;
    while (std::getline(dropFile, line))
    {
        std::vector<std::string> dropFields = splitCSV(line);
        if (dropFields.size() >= 1 && dropFields[0] == studentID)
        {
            return true;
        }
    }

    dropFile.close();
    return false;
}

// Function to update the drop.csv file with new or existing drop information
void updateDropCSV(const std::string &studentID, const std::string &stopID, const std::string &routeID)
{
    std::ifstream dropFile("drop.csv");
    if (!dropFile)
    {
        std::cout << "Error opening drop.csv file.\n";
        return;
    }

    std::string line;
    std::vector<std::string> dropData;
    bool foundStudentID = false;

    while (std::getline(dropFile, line))
    {
        std::vector<std::string> dropFields = splitCSV(line);
        if (dropFields.size() >= 1 && dropFields[0] == studentID)
        {
            line = studentID + "," + stopID + "," + routeID;
            foundStudentID = true;
        }
        dropData.push_back(line);
    }

    dropFile.close();

    if (!foundStudentID)
    {
        // If the student ID was not found, append a new row to the data
        std::string newLine = studentID + "," + stopID + "," + routeID;
        dropData.push_back(newLine);
    }

    std::ofstream dropFileOut("drop.csv");
    if (!dropFileOut)
    {
        std::cout << "Error opening drop.csv file.\n";
        return;
    }

    // Write back the modified drop data
    for (const auto &line : dropData)
    {
        dropFileOut << line << "\n";
    }

    dropFileOut.close();
}

void dropFunctionality(const std::string &studentID, const std::string &routeID)
{
    std::cout << "Available Drop Stops for your route:\n";
    displayAvailableStopsForRoute(routeID);

    std::string stopID;
    std::cout << "Enter the Stop ID where you want to drop: ";
    std::cin >> stopID;

    // Check if the student ID exists in drop.csv
    bool studentExists = isStudentIDExistsInDrop(studentID);

    // Update the drop.csv file with new or existing drop information
    updateDropCSV(studentID, stopID, routeID);

    if (studentExists)
    {
        std::cout << "Drop information updated successfully!\n";
    }
    else
    {
        std::cout << "Drop information saved successfully!\n";
    }
}

// Function to find a student's route based on their studentID
std::string findStudentRoute(const std::string &studentID)
{
    std::ifstream studentFile("student.csv");
    if (!studentFile)
    {
        std::cout << "Error opening student.csv file.\n";
        return "";
    }

    std::string line;
    while (std::getline(studentFile, line))
    {
        std::vector<std::string> studentFields = splitCSV(line);
        if (studentFields.size() >= 5 && studentFields[0] == studentID)
        {
            return studentFields[3]; // Return student_route_id
        }
    }

    studentFile.close();
    return "";
}

// Function to check if a value exists in the specified CSV file column
bool isValueExistsInCSV(const std::string &filename, const std::string &value, int columnIndex)
{
    std::ifstream file(filename);
    if (!file)
    {
        std::cout << "Error opening " << filename << " file.\n";
        return false;
    }

    std::string line;
    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        std::string cell;
        int column = 0;
        while (std::getline(iss, cell, ','))
        {
            if (column == columnIndex && cell == value)
            {
                file.close();
                return true;
            }
            column++;
        }
    }

    file.close();
    return false;
}

int getIntInput()
{
    int value;
    while (true)
    {
        std::cout << "Enter your choice: ";
        if (std::cin >> value)
        {
            // Valid integer input
            break;
        }
        else
        {
            std::cin.clear();                                                   // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the rest of the input buffer
            std::cout << "Invalid input. Please enter a valid integer.\n";
        }
    }
    return value;
}

// Function to display the admin menu and handle admin options
void adminMenu()
{
    while (true)
    {
        bool backToAdminMenu = false;
        std::cout << "\n--- Admin Menu ---\n";
        std::cout << "1. Bus\n";
        std::cout << "2. Drivers\n";
        std::cout << "3. Register Student\n";
        std::cout << "4. Register Admin\n";
        std::cout << "5. Routes\n";
        std::cout << "6. Stops\n";
        std::cout << "7. Logout\n";

        int choice;
        choice = getIntInput();

        switch (choice)
        {
        case 1:
        {
            while (!backToAdminMenu)
            {
                std::cout << "\n--- Bus Menu ---\n";
                std::cout << "1. View buses\n";
                std::cout << "2. Add new bus\n";
                std::cout << "3. Edit bus\n";
                std::cout << "4. Delete bus\n";
                std::cout << "5. Back to Admin Menu\n";

                int busChoice;
                busChoice = getIntInput();

                switch (busChoice)
                {
                case 1:
                {
                    // Option 1: View buses
                    std::vector<std::string> busesData = readCSV("bus.csv");
                    if (busesData.size() <= 1)
                    {
                        std::cout << "No buses found.\n";
                    }
                    else
                    {
                        std::cout << "Bus List:\n";
                        for (size_t i = 1; i < busesData.size(); ++i)
                        {
                            std::vector<std::string> busFields = splitCSV(busesData[i]);
                            std::cout << "Bus ID: " << busFields[0] << ", Bus Number: " << busFields[1]
                                      << ", Bus Route ID: " << busFields[2] << ", Bus Capacity: " << busFields[3] << "\n";
                        }
                    }
                    break;
                }
                case 2:
                {
                    // Option 2: Add new bus
                    std::string busNumber, busRouteID, busCapacity;
                    std::cout << "Enter Bus Number: ";
                    std::cin.ignore(); // Ignore the newline character left by previous input
                    std::getline(std::cin, busNumber);
                    std::cout << "Enter Bus Route ID: ";
                    std::cin >> busRouteID;
                    std::cout << "Enter Bus Capacity: ";
                    std::cin >> busCapacity;

                    // Verify if the route_id exists in route.csv before adding the bus
                    if (!isValueExistsInCSV("routes.csv", busRouteID, 0))
                    {
                        std::cout << "Error: Route not found with the given ID. Bus not added.\n";
                    }
                    else
                    {
                        // Get the highest bus_id and increment it for the new bus
                        std::vector<std::string> busesData = readCSV("bus.csv");
                        int highestBusID = 0;
                        for (size_t i = 1; i < busesData.size(); ++i)
                        {
                            std::vector<std::string> busFields = splitCSV(busesData[i]);
                            int busID = std::stoi(busFields[0]);
                            if (busID > highestBusID)
                            {
                                highestBusID = busID;
                            }
                        }
                        int newBusID = highestBusID + 1;

                        // Add the new bus to the bus.csv file
                        std::string newBusData = std::to_string(newBusID) + "," + busNumber + "," + busRouteID + "," + busCapacity;
                        busesData.push_back(newBusData);
                        writeCSV("bus.csv", busesData);

                        std::cout << "New bus added successfully.\n";
                    }

                    break;
                }
                case 3:
                {
                    // Option 3: Edit bus
                    std::string busID;
                    std::cout << "Enter the ID of the bus you want to edit: ";
                    std::cin >> busID;

                    std::vector<std::string> busesData = readCSV("bus.csv");
                    bool busFound = false;
                    for (size_t i = 1; i < busesData.size(); ++i)
                    {
                        std::vector<std::string> busFields = splitCSV(busesData[i]);
                        if (busFields[0] == busID)
                        {
                            busFound = true;

                            // Get updated information from the user
                            std::string busNumber, busRouteID, busCapacity;
                            std::cout << "Enter new Bus Number: ";
                            std::cin.ignore(); // Ignore the newline character left by previous input
                            std::getline(std::cin, busNumber);
                            std::cout << "Enter new Bus Route ID: ";
                            std::cin >> busRouteID;
                            std::cout << "Enter new Bus Capacity: ";
                            std::cin >> busCapacity;

                            // Verify if the route_id exists in route.csv before updating the bus
                            if (!isValueExistsInCSV("routes.csv", busRouteID))
                            {
                                std::cout << "Error: Route not found with the given ID. Bus not updated.\n";
                            }
                            else
                            {
                                // Update the bus information in the busesData vector
                                busFields[1] = busNumber;
                                busFields[2] = busRouteID;
                                busFields[3] = busCapacity;
                                busesData[i] = joinCSV(busFields); // Use the joinCSV function
                                writeCSV("bus.csv", busesData);
                                std::cout << "Bus updated successfully.\n";
                            }
                            break;
                        }
                    }
                    if (!busFound)
                    {
                        std::cout << "Error: Bus not found with the given ID.\n";
                    }
                    break;
                }
                case 4:
                {
                    // Option 4: Delete bus
                    std::string busID;
                    std::cout << "Enter the ID of the bus you want to delete: ";
                    std::cin >> busID;

                    std::vector<std::string> busesData = readCSV("bus.csv");
                    bool busFound = false;
                    for (size_t i = 1; i < busesData.size(); ++i)
                    {
                        std::vector<std::string> busFields = splitCSV(busesData[i]);
                        if (busFields[0] == busID)
                        {
                            busFound = true;
                            busesData.erase(busesData.begin() + i);
                            writeCSV("bus.csv", busesData);
                            std::cout << "Bus deleted successfully.\n";
                            break;
                        }
                    }
                    if (!busFound)
                    {
                        std::cout << "Error: Bus not found with the given ID.\n";
                    }
                    break;
                }
                case 5:
                {
                    backToAdminMenu = true;
                    break;
                }
                default:
                {
                    std::cout << "Invalid option. Please try again.\n";
                    break;
                }
                }
            }
        }
        case 2:
        {
            // Option 2: Drivers
            while (!backToAdminMenu)
            {
                std::cout << "\n--- Driver Menu ---\n";
                std::cout << "1. View drivers\n";
                std::cout << "2. Add new driver\n";
                std::cout << "3. Edit driver\n";
                std::cout << "4. Delete driver\n";
                std::cout << "5. Back to Admin Menu\n";

                int driverChoice;
                driverChoice = getIntInput();

                switch (driverChoice)
                {
                case 1:
                {
                    // Option 1: View drivers
                    viewDrivers(); // Call the viewDrivers function to display all drivers
                    break;
                }
                case 2:
                {
                    // Option 2: Add new driver
                    addNewDriver(); // Call the addNewDriver function to add a new driver
                    break;
                }
                case 3:
                {
                    // Option 3: Edit driver
                    editDriver(); // Call the editDriver function to edit a driver
                    break;
                }
                case 4:
                {
                    // Option 4: Delete driver
                    deleteDriver(); // Call the deleteDriver function to delete a driver
                    break;
                }
                case 5:
                {
                    backToAdminMenu = true;
                    break;
                }
                default:
                {
                    std::cout << "Invalid option. Please try again.\n";
                    break;
                }
                }

                if (driverChoice == 5)
                {
                    break;
                }
            }

            break; // Break from the outer loop to display Admin Menu again
        }
        case 3:
        {
            // Option 3: Register Student
            while (!backToAdminMenu)
            {
                std::cout << "\n--- Register Student Menu ---\n";
                std::cout << "1. View Students\n";
                std::cout << "2. Add new Student\n";
                std::cout << "3. Edit Student\n";
                std::cout << "4. Delete Student\n";
                std::cout << "5. Back to Admin Menu\n";

                int studentChoice;
                studentChoice = getIntInput();

                switch (studentChoice)
                {
                case 1:
                {
                    // Option 1: View Students
                    viewStudents(); // Call the viewStudents function to display all students
                    break;
                }
                case 2:
                {
                    // Option 2: Add new Student
                    addNewStudent(); // Call the addNewStudent function to add a new student
                    break;
                }
                case 3:
                {
                    // Option 3: Edit Student
                    editStudent(); // Call the editStudent function to edit a student
                    break;
                }
                case 4:
                {
                    // Option 4: Delete Student
                    deleteStudent(); // Call the deleteStudent function to delete a student
                    break;
                }
                case 5:
                {
                    backToAdminMenu = true;
                    break;
                }
                default:
                {
                    std::cout << "Invalid option. Please try again.\n";
                    break;
                }
                }

                if (studentChoice == 5)
                {
                    break;
                }
            }
            break;
        }
        case 4:
        {
            // Option 4: Register Admin
            while (!backToAdminMenu)
            {
                std::cout << "\n--- Register Admin Menu ---\n";
                std::cout << "1. View Admins\n";
                std::cout << "2. Add new Admin\n";
                std::cout << "3. Edit Admin\n";
                std::cout << "4. Delete Admin\n";
                std::cout << "5. Back to Admin Menu\n";

                int adminChoice;
                adminChoice = getIntInput();

                switch (adminChoice)
                {
                case 1:
                {
                    // Option 1: View Admins
                    viewAdmins(); // Call the viewAdmins function to display all admins
                    break;
                }
                case 2:
                {
                    // Option 2: Add new Admin
                    addNewAdmin(); // Call the addNewAdmin function to add a new admin
                    break;
                }
                case 3:
                {
                    // Option 3: Edit Admin
                    editAdmin(); // Call the editAdmin function to edit an admin
                    break;
                }
                case 4:
                {
                    // Option 4: Delete Admin
                    deleteAdmin(); // Call the deleteAdmin function to delete an admin
                    break;
                }
                case 5:
                {
                    backToAdminMenu = true;
                    break;
                }
                default:
                {
                    std::cout << "Invalid option. Please try again.\n";
                    break;
                }
                }

                if (adminChoice == 5)
                {
                    break;
                }
            }

            break;
        }
        case 5:
        {
            // Option 5: Routes
            while (!backToAdminMenu)
            {
                std::cout << "\n--- Routes Menu ---\n";
                std::cout << "1. View Routes\n";
                std::cout << "2. Add new Route\n";
                std::cout << "3. Edit Route\n";
                std::cout << "4. Delete Route\n";
                std::cout << "5. Back to Admin Menu\n";

                int routeChoice;
                routeChoice = getIntInput();

                switch (routeChoice)
                {
                case 1:
                {
                    // Option 1: View Routes
                    viewRoutes();
                    break;
                }
                case 2:
                {
                    // Option 2: Add new Route
                    addNewRoute();
                    break;
                }
                case 3:
                {
                    // Option 3: Edit Route
                    editRoute();
                    break;
                }
                case 4:
                {
                    // Option 4: Delete Route
                    deleteRoute();
                    break;
                }
                case 5:
                {
                    backToAdminMenu = true;
                    break;
                }
                default:
                {
                    std::cout << "Invalid option. Please try again.\n";
                    break;
                }
                }

                if (routeChoice == 5)
                {
                    break;
                }
            }

            break;
        }
        case 6:
        {
            // Option 6: Stops
            while (!backToAdminMenu)
            {
                std::cout << "\n--- Stops Menu ---\n";
                std::cout << "1. View Stops\n";
                std::cout << "2. Add new Stops\n";
                std::cout << "3. Edit Stops\n";
                std::cout << "4. Delete Stops\n";
                std::cout << "5. Back to Admin Menu\n";

                int stopsChoice;
                stopsChoice = getIntInput();

                switch (stopsChoice)
                {
                case 1:
                {
                    // Option 1: View Stops
                    viewStops();
                    break;
                }
                case 2:
                {
                    // Option 2: Add new Stops
                    addNewStop();
                    break;
                }
                case 3:
                {
                    // Option 3: Edit Stops
                    editStop();
                    break;
                }
                case 4:
                {
                    // Option 4: Delete Stops
                    deleteStop();
                    break;
                }
                case 5:
                {
                    backToAdminMenu = true;
                    break;
                }
                default:
                {
                    std::cout << "Invalid option. Please try again.\n";
                    break;
                }
                }

                if (stopsChoice == 5)
                {
                    break;
                }
            }

            break;
        }
        case 7:
        {
            // Option 7: Logout
            return; // Return to main menu
        }
        default:
        {
            std::cout << "Invalid option. Please try again.\n";
            break;
        }
        }
    }
}

// Function to handle student login
std::string studentLogin()
{
    std::string username, password;
    std::cout << "Enter Student Username: ";
    std::cin >> username;
    std::cout << "Enter Student Password: ";
    std::cin >> password;

    // Check if student credentials are correct
    std::vector<std::string> studentData = readCSV("student.csv");
    for (const std::string &line : studentData)
    {
        std::vector<std::string> fields = splitCSV(line);
        if (fields[4] == username && fields[5] == password)
        {
            return fields[0];
        }
    }

    return 0;
}

// Function to display the student menu and handle student options
void studentMenu(const std::string &studentID)
{
    while (true)
    {
        std::string routeID;

        routeID = findStudentRoute(studentID);
        std::cout << "\n--- Student Menu ---\n";
        std::cout << "1. Pick up\n";
        std::cout << "2. Drop\n";
        std::cout << "3. Logout\n";

        int choice;
        choice = getIntInput();

        if (routeID.empty())
        {
            std::cout << "Student not found or route not assigned for the given student ID.\n";
            return;
        }
        switch (choice)
        {
        case 1:
        {
            // Option 1: Pick up
            pickUpFunctionality(studentID, routeID);
            break;
        }
        case 2:
        {
            // Option 2: Drop
            dropFunctionality(studentID, routeID);
            break;
        }
        case 3:
        {
            // Option 3: Logout
            return; // Return to main menu
        }
        default:
        {
            std::cout << "Invalid option. Please try again.\n";
            break;
        }
        }
    }
}

// Function to handle driver login
bool driverLogin()
{
    std::string username, password;
    std::cout << "Enter Driver Username: ";
    std::cin >> username;
    std::cout << "Enter Driver Password: ";
    std::cin >> password;

    // Check if driver credentials are correct
    std::vector<std::string> driverData = readCSV("driver.csv");
    for (const std::string &line : driverData)
    {
        std::vector<std::string> fields = splitCSV(line);
        if (fields[3] == username && fields[4] == password)
        {
            return true;
        }
    }

    return false;
}

// Function to display pick-up data from pick.csv for the given driver route_id
void displayPickDataForDriver(const std::string &driverRouteID)
{
    std::ifstream pickFile("pick.csv");
    if (!pickFile)
    {
        std::cout << "Error opening pick.csv file.\n";
        return;
    }

    std::string line;
    std::cout << "Pick-up Stops for your route:\n";
    while (std::getline(pickFile, line))
    {
        std::vector<std::string> pickFields = splitCSV(line);
        if (pickFields.size() >= 3 && pickFields[2] == driverRouteID)
        {
            std::cout << "Student ID: " << pickFields[0] << ", Stop ID: " << pickFields[1] << ", Route ID: " << pickFields[2] << "\n";
        }
    }

    pickFile.close();
}

// Function to display drop data from drop.csv for the given driver route_id
void displayDropDataForDriver(const std::string &driverRouteID)
{
    std::ifstream dropFile("drop.csv");
    if (!dropFile)
    {
        std::cout << "Error opening drop.csv file.\n";
        return;
    }

    std::string line;
    std::cout << "Drop Stops for your route:\n";
    while (std::getline(dropFile, line))
    {
        std::vector<std::string> dropFields = splitCSV(line);
        if (dropFields.size() >= 3 && dropFields[2] == driverRouteID)
        {
            std::cout << "Student ID: " << dropFields[0] << ", Stop ID: " << dropFields[1] << ", Route ID: " << dropFields[2] << "\n";
        }
    }

    dropFile.close();
}

// Function to display the driver menu and handle driver options
void driverMenu()
{
    while (true)
    {
        std::cout << "\n--- Driver Menu ---\n";
        std::cout << "1. Pick up stops\n";
        std::cout << "2. Drop stops\n";
        std::cout << "3. Logout\n";

        int choice;
        choice = getIntInput();

        switch (choice)
        {
        case 1:
        {
            // Option 1: Pick up stops
            std::string driverRouteID;
            std::cout << "Enter your bus route ID: ";
            std::cin >> driverRouteID;

            displayPickDataForDriver(driverRouteID);

            break;
        }
        case 2:
        {
            // Option 2: Drop stops
            std::string driverRouteID;
            std::cout << "Enter your bus route ID: ";
            std::cin >> driverRouteID;

            displayDropDataForDriver(driverRouteID);

            break;
        }
        case 3:
        {
            // Option 3: Logout
            return; // Return to main menu
        }
        default:
        {
            std::cout << "Invalid option. Please try again.\n";
            break;
        }
        }
    }
}

int main()
{
    try
    {
        std::string studentID;
        while (true)
        {
            std::cout << "\n--- Automated Transports Management System ---\n";
            std::cout << "1. Admin Login\n";
            std::cout << "2. Student Login\n";
            std::cout << "3. Driver Login\n";
            std::cout << "4. Exit\n";

            int choice;
            choice = getIntInput();

            switch (choice)
            {
            case 1:
            {
                // Option 1: Admin Login
                if (adminLogin())
                {
                    adminMenu();
                }
                else
                {
                    std::cout << "Invalid admin username or password. Please try again.\n";
                }
                break;
            }
            case 2:
            {
                // Option 2: Student Login
                studentID = studentLogin();
                if (stoi(studentID))
                {
                    studentMenu(studentID);
                }
                else
                {
                    std::cout << "Invalid student username or password. Please try again.\n";
                }
                break;
            }
            case 3:
            {
                // Option 3: Driver Login
                if (driverLogin())
                {
                    driverMenu();
                }
                else
                {
                    std::cout << "Invalid driver username or password. Please try again.\n";
                }
                break;
            }
            case 4:
            {
                // Option 4: Exit
                std::cout << "Exiting the program...\n";
                return 0;
            }
            default:
            {
                std::cout << "Invalid option. Please try again.\n";
                break;
            }
            }
        }
    }
    catch (const std::runtime_error &error)
    {
        std::cerr << "Runtime error occurred: " << error.what() << std::endl;
    }
    catch (const std::exception &error)
    {
        std::cerr << "Some other exception occurred: " << error.what() << std::endl;
    }
    catch (...)
    {
        std::cerr << "Unknown exception occurred." << std::endl;
    }
    return 0;
}

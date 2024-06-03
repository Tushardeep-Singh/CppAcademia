// Author: Tushardeep Singh
// Seneca College Alumni

#ifndef SENECA_EMAILFILE_H
#define SENECA_EMAILFILE_H
#include <iostream>
#include <fstream>
#include <string>

namespace seneca
{

	const int BUFFER_SIZE = 1024; // Maximum possible size for all the fields of the Email record

	class EmailFile;
	class Email
	{
	private:
		// Email string
		char *m_email{nullptr};
		// Person name string
		char *m_name{nullptr};
		char m_year[5]{'\0'};
		// EmailFile can access the private members
		friend class EmailFile;

	public:
		// Default constructor
		Email(){};
		// Delete copy constructor
		Email(const Email &) = delete;
		// Copy assignment operator
		Email &operator=(const Email &);
		// Reads data from an input file stream and populates the Email object's members
		bool load(std::ifstream &in);
		// Destructor
		~Email();
	};

	class EmailFile
	{
	private:
		// Pointer to hold an array of Email objects
		Email *m_emailLines{nullptr};
		// Pointer to hold the name of the file containing the Email data
		char *m_filename{nullptr};
		// Number of emails in m_emailLines
		int m_noOfEmails{0};
		// Dynamically allocates a Cstring in m_filename and copies the content of the filename argument into it
		void setFilename(const char *filename);
		// Sets the EmailFile to default state
		void setEmpty();
		// Counts number of emails in m_filename
		bool setNoOfEmails();
		// Adds emails to m_emailLines using Email::load()
		void loadEmails();
		// Helper function for copy constructor and copy Assignment operator
		void copyEmailFile(const EmailFile &copyFromEmailFile);
		// Returns true if all members variables are valid
		bool isValidObj(const EmailFile &obj) const;
		// Deallocates m_emailLines object
		void destroyEmails(Email *&emailLines, int noOfEmails);

	public:
		// Default constructor
		EmailFile();
		// Constructor to load emails if filename is valid
		EmailFile(const char *filename);
		// Displays the m_emailLines content
		std::ostream &view(std::ostream &ostr) const;
		// Operator overload
		operator bool() const;
		// Copy constructor
		EmailFile(const EmailFile &copyFromEmailFile);
		// Copy assignment operator
		EmailFile &operator=(const EmailFile &copyFromEmailFile);
		// Destructor
		~EmailFile();
		// Writes data to "filename" from the current m_emailLines object
		bool saveToFile(const char *filename) const;
		// Implementation defined
		void fileCat(const EmailFile &obj, const char *name = nullptr);
	};
	// Overload << operator
	std::ostream &operator<<(std::ostream &ostr, const EmailFile &text);

}
#endif // !SENECA_EMAILFILE_H

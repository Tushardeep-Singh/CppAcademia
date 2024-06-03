// Author: Tushardeep Singh
// Seneca College Alumni

#define _CRT_SECURE_NO_WARNINGS

#include <fstream>
#include <cstring>
#include "EmailFile.h"

using namespace std;
namespace seneca
{
    Email &Email::operator=(const Email &rhs)
    {
        // Self assignment check
        if (this != &rhs && rhs.m_email && rhs.m_name)
        {
            delete[] m_email;
            m_email = nullptr;
            m_email = new char[strlen(rhs.m_email) + 1];
            strcpy(m_email, rhs.m_email);
            delete[] m_name;
            m_name = nullptr;
            m_name = new char[strlen(rhs.m_name) + 1];
            strcpy(m_name, rhs.m_name);
            strcpy(m_year, rhs.m_year);
        }

        return *this;
    }

    bool Email::load(std::ifstream &in)
    {
        char buffer[BUFFER_SIZE];
        bool result = false;

        if (in.getline(buffer, BUFFER_SIZE, ','))
        {
            delete[] m_email;
            m_email = new char[strlen(buffer) + 1];
            strcpy(m_email, buffer);

            if (in.getline(buffer, BUFFER_SIZE, ','))
            {
                delete[] m_name;
                m_name = new char[strlen(buffer) + 1];
                strcpy(m_name, buffer);

                if (in.getline(buffer, BUFFER_SIZE, '\n'))
                {
                    strcpy(m_year, buffer);
                    result = true;
                }
            }
        }
        return result;
    }

    Email::~Email()
    {
        delete[] m_name;
        delete[] m_email;
    }

    void EmailFile::setFilename(const char *filename)
    {
        delete[] m_filename;
        m_filename = nullptr;
        if (filename)
        {
            m_filename = new char[strlen(filename) + 1];
            m_filename[0] = '\0';
            strcpy(m_filename, filename);
        }
    }

    void EmailFile::setEmpty()
    {
        if (m_emailLines != nullptr)
        {
            delete[] m_emailLines;
            m_emailLines = nullptr;
        }
        if (m_filename != nullptr)
        {
            delete[] m_filename;
            m_filename = nullptr;
        }
        m_noOfEmails = 0;
    }

    bool EmailFile::setNoOfEmails()
    {
        bool isValid = false;
        ifstream file(m_filename);

        if (!file.is_open())
        {
            cout << "Failed to open file: " << m_filename << endl;
        }
        else
        {
            m_noOfEmails = 0;
            char line[BUFFER_SIZE];
            while (file.getline(line, BUFFER_SIZE))
            {
                ++m_noOfEmails;
            }
            file.close();
            isValid = true;
        }
        return isValid;
    }

    std::ostream &EmailFile::view(std::ostream &ostr) const
    {
        if (m_filename)
        {
            ostr << m_filename << endl;
            ostr.width(strlen(m_filename));
            ostr.fill('=');
            ostr << "=" << endl;
            ostr.fill(' ');
            for (int i = 0; i < m_noOfEmails; i++)
            {
                ostr.width(35);
                ostr.setf(ios::left);
                ostr << m_emailLines[i].m_email;
                ostr.width(25);
                ostr << m_emailLines[i].m_name;
                ostr << "Year = " << m_emailLines[i].m_year << endl;
            }
        }

        return ostr;
    }

    std::ostream &operator<<(std::ostream &ostr, const EmailFile &text)
    {
        return text.view(ostr);
    }

    void EmailFile::loadEmails()
    {
        if (m_filename)
        {
            if (m_emailLines)
            {
                delete[] m_emailLines;
                m_emailLines = nullptr;
            }
            std::ifstream emailFile(m_filename);

            if (emailFile.is_open())
            {
                m_emailLines = new Email[m_noOfEmails];
                for (int i = 0; i < m_noOfEmails; ++i)
                    m_emailLines[i].load(emailFile);
            }
            emailFile.close();
        }
    }

    EmailFile::operator bool() const
    {
        return m_emailLines != nullptr || m_filename != nullptr || m_noOfEmails != 0;
    }

    EmailFile::EmailFile()
    {
        m_emailLines = nullptr;
        m_filename = nullptr;
        m_noOfEmails = 0;
    }

    EmailFile::EmailFile(const char *filename)
    {
        if (!filename)
        {
            setEmpty();
            return;
        }
        setFilename(filename);
        if (setNoOfEmails())
            loadEmails();
        else
            setEmpty();
    }

    void EmailFile::copyEmailFile(const EmailFile &copyFromEmailFile)
    {
        if (!this->m_emailLines)
            setEmpty();
        m_noOfEmails = copyFromEmailFile.m_noOfEmails;
        m_emailLines = new Email[m_noOfEmails];
        for (int i = 0; i < m_noOfEmails; ++i)
            m_emailLines[i] = copyFromEmailFile.m_emailLines[i];
        setFilename(copyFromEmailFile.m_filename);
    }

    EmailFile::EmailFile(const EmailFile &copyFromEmailFile)
    {
        this->copyEmailFile(copyFromEmailFile);
    }

    EmailFile &EmailFile::operator=(const EmailFile &copyFromEmailFile)
    {
        if (this != &copyFromEmailFile)
            this->copyEmailFile(copyFromEmailFile);
        return *this;
    }

    EmailFile::~EmailFile()
    {
        if (m_noOfEmails != 0 && m_emailLines)
        {
            for (int i = 0; i < m_noOfEmails; ++i)
            {
                delete[] m_emailLines[i].m_email;
                delete[] m_emailLines[i].m_name;
                m_emailLines[i].m_email = nullptr;
                m_emailLines[i].m_name = nullptr;
            }
            delete[] m_emailLines;
            m_emailLines = nullptr;
        }

        if (m_filename)
        {
            delete[] m_filename;
            m_filename = nullptr;
        }
        m_noOfEmails = 0;
    }

    bool EmailFile::saveToFile(const char *filename) const
    {
        std::ofstream writeData(filename);
        if (!writeData.is_open())
        {
            std::cerr << "Error: Could not open file: " << filename << '\n';
            return false;
        }

        for (int i = 0; i < m_noOfEmails; ++i)
            writeData << m_emailLines[i].m_email << ',' << m_emailLines[i].m_name << ',' << m_emailLines[i].m_year << '\n';

        writeData.close();
        return true;
    }

    void EmailFile::fileCat(const EmailFile &obj, const char *name)
    {
        if (isValidObj(*this) && isValidObj(obj))
        {
            EmailFile newEmailLines;
            newEmailLines.m_noOfEmails = this->m_noOfEmails + obj.m_noOfEmails;
            newEmailLines.m_emailLines = new Email[newEmailLines.m_noOfEmails];
            int i = 0;
            for (; i < this->m_noOfEmails; ++i)
                newEmailLines.m_emailLines[i] = m_emailLines[i];
            int itr = 0;
            for (; i < newEmailLines.m_noOfEmails; ++i)
                newEmailLines.m_emailLines[i] = obj.m_emailLines[itr++];

            if (!name)
            {
                destroyEmails(m_emailLines, m_noOfEmails);
                m_emailLines = new Email[newEmailLines.m_noOfEmails];
                m_noOfEmails = newEmailLines.m_noOfEmails;
                for (int i = 0; i < m_noOfEmails; ++i)
                    m_emailLines[i] = newEmailLines.m_emailLines[i];
                destroyEmails(newEmailLines.m_emailLines, newEmailLines.m_noOfEmails);
                return;
            }
            newEmailLines.saveToFile(name);
            destroyEmails(newEmailLines.m_emailLines, newEmailLines.m_noOfEmails);
        }
    }

    bool EmailFile::isValidObj(const EmailFile &obj) const
    {
        return obj.m_emailLines && obj.m_filename && obj.m_noOfEmails;
    }

    void EmailFile::destroyEmails(Email *&emailLines, int noOfEmails)
    {
        for (int i = 0; i < noOfEmails; ++i)
        {
            delete[] emailLines[i].m_email;
            delete[] emailLines[i].m_name;
            emailLines[i].m_email = nullptr;
            emailLines[i].m_name = nullptr;
        }
        delete[] emailLines;
        emailLines = nullptr;
    }
}
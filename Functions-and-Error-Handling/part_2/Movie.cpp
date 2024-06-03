// Author: Tushardeep Singh
// Seneca College Alumni

#include "Movie.h"

namespace seneca
{
  Movie::Movie()
  {
    m_movieTitle = "";
    m_movieReleaseYear = 0;
    m_movieDescription = "";
  }

  const std::string &Movie::title() const
  {
    return m_movieTitle;
  }

  void Movie::removeLeadTrailSpaces(std::string &str)
  {
    int idx1, idx2;
    for (int i = 0; i < str.length(); ++i)
      if (str[i] != ' ')
      {
        idx1 = i;
        break;
      }

    for (int i = str.length() - 1; i >= 0; --i)
      if (str[i] != ' ')
      {
        idx2 = i;
        break;
      }

    str = str.substr(idx1, idx2 - idx1 + 1);
  }

  Movie::Movie(const std::string &strMovie)
  {
    int idx1 = strMovie.find_first_of(',');
    m_movieTitle = strMovie.substr(0, idx1);
    removeLeadTrailSpaces(m_movieTitle);

    int idx2 = strMovie.find_first_of(',', idx1 + 1);
    std::string yearUtils = strMovie.substr(idx1 + 1, idx2 - idx1 - 1);
    removeLeadTrailSpaces(yearUtils);
    m_movieReleaseYear = std::stoi(yearUtils);

    m_movieDescription = strMovie.substr(idx2 + 1);
    removeLeadTrailSpaces(m_movieDescription);
  }

  const int &Movie::getMovieReleaseYear() const
  {
    return m_movieReleaseYear;
  }

  const std::string &Movie::getMovieDescription() const
  {
    return m_movieDescription;
  }

  std::ostream &operator<<(std::ostream &output, const Movie &outputMovie)
  {
    output << std::setw(40) << std::right << outputMovie.title();
    output << " | ";
    output << std::setw(4) << outputMovie.getMovieReleaseYear();
    output << " | ";
    output << outputMovie.getMovieDescription() << '\n';

    return output;
  }

  Movie& Movie::operator=(const Movie& copyFromMovie)
  {
    m_movieTitle = copyFromMovie.title();
    m_movieReleaseYear = copyFromMovie.getMovieReleaseYear();
    m_movieDescription = copyFromMovie.getMovieDescription();

    return *this;
  }
}
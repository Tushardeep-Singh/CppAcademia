// Author: Tushardeep Singh
// Seneca College Alumni

#ifndef SENECA_MOVIE_H
#define SENECA_MOVIE_H

#include <string>
#include <iomanip>

namespace seneca
{
  class Movie
  {
  private:
    // Title of the movie
    std::string m_movieTitle;
    // Release year of the movie
    int m_movieReleaseYear;
    // Description of the movie
    std::string m_movieDescription;

  public:
    // Default constructor
    Movie();
    // Getter: returns the title of the movie (m_movieTitle)
    const std::string &title() const;
    // Getter: returns the release year of the movie (m_movieReleaseYear)
    const int &getMovieReleaseYear() const;
    // Getter: returns the description of the movie (m_movieDescription)
    const std::string &getMovieDescription() const;
    // 1-arg constructor
    Movie(const std::string &strMovie);
    // Removes leading and trailing whitespaces from param string 'str'
    void removeLeadTrailSpaces(std::string &str);
    // Copy assignment operator
    Movie &operator=(const Movie &copyFromMovie);

    // Templated function to replace bad words from title and description of movie
    template <typename T>
    void fixSpelling(T &spellChecker);
  };

  // Templated function to replace bad words from title and description of movie
  template <typename T>
  void Movie::fixSpelling(T &spellChecker)
  {
    spellChecker(m_movieTitle);
    spellChecker(m_movieDescription);
  }

  // Overloading the insertion operator
  std::ostream &operator<<(std::ostream &output, const Movie &outputMovie);
}

#endif
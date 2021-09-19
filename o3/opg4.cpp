#include <iostream>
int main() {
  std::cout << "skriv inn tre ord:" << std::endl;
  std::string word1, word2, word3;
  std::cin >> word1;
  std::cin >> word2;
  std::cin >> word3;

  std::string sentence = word1 + " " + word2 + " " + word3 + ".";
  std::cout << sentence << std::endl;
  std::cout << "length of word 1: " << word1.length() << std::endl;
  std::cout << "length of word 2: " << word2.length() << std::endl;
  std::cout << "length of word 3: " << word3.length() << std::endl;
  std::cout << "length of sentence: " << sentence.length() << std::endl;

  std::string sentence2 = sentence;

  if (sentence2.length() > 11) {
    sentence2 = sentence2.substr(0, 10) + "xxx" + sentence2.substr(13, sentence2.length());
  }
  std::cout << sentence << std::endl;
  std::cout << sentence2 << std::endl;

  std::string sentence_start;
  // string er et objekt så går ut ifra at dette er greit
  if (sentence.length() > 4) {
    sentence_start = sentence.substr(0, 5);
    std::cout << "sentence: " << sentence << std::endl;
    std::cout << "sentence start: " << sentence_start << std::endl;
  }
  std::cout << "sentence contains hallo?: " << (sentence.find("hallo") != std::string::npos ? "true" : "false") << std::endl;

  auto position = sentence.find("er");
  while (position != std::string::npos) {
    std::cout << "er found at: " << position << std::endl;
    ++position;
    position = sentence.find("er", position);
  }
  std::cout << "no more instances of er found" << std::endl;
}
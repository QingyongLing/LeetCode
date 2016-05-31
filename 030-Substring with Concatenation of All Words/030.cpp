/*
You are given a string, s, and a list of words, words, that are all of the same length.
 Find all starting indices of substring(s) in s that is a concatenation of each word in
  words exactly once and without any intervening characters.
For example, given:
s: "barfoothefoobarman"
words: ["foo", "bar"]
You should return the indices: [0,9].
 (order does not matter).

 Author=Ling
 Date=2016.5.31
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
class Solution {
public:
  //Runtime: 52 ms
  vector<int> findSubstring(string s, vector<string>& words)
  {
      vector<int> result;
      if (s.size() == 0 || words.size() == 0)
          return result;
      if (s.size() < words[0].size())
          return result;
      int subsize = words[0].size();
      hash<string> str_hash;
      vector<size_t> hash_table_s;
      map<size_t, int> hash_table_words;
      for (int i = 0; i <= s.size() - subsize; ++i)
      {
          hash_table_s.push_back(str_hash(s.substr(i, subsize)));
      }
      for (int i = 0; i < words.size(); ++i)
      {
          ++hash_table_words[str_hash(words[i])];
      }
      for (int i = 0; i < subsize; ++i)
      {
          int left = i, count = 0;
          map<size_t, int> legal;
          for (int j = i; j < hash_table_s.size(); j += subsize)
          {
              if (count < words.size())
              {
                  auto iter = hash_table_words.find(hash_table_s[j]);
                  if (iter == hash_table_words.end())
                  {
                      count = 0;
                      legal.clear();
                      left = j + subsize;
                  }
                  else
                  {
                      ++count;
                      int num = ++legal[iter->first];
                      if (num > iter->second)
                      {
                          do
                          {
                              --count;
                              --legal[hash_table_s[left]];
                              left += subsize;
                          } while (hash_table_s[left - subsize] != iter->first);
                      }
                      if (count == words.size())
                      {
                          result.push_back(left);
                          --count;
                          --legal[hash_table_s[left]];
                          left += subsize;
                      }
                  }
              }
          }
      }
      return result;
  }
  //Runtime: 348 ms
  vector<int> findSubstring2(string s, vector<string>& words)
  {
      vector<int> result;
      if (s.size() == 0 || words.size() == 0)
          return result;
      if (s.size() < words[0].size())
          return result;
      int subsize = words[0].size();
      hash<string> str_hash;
      vector<size_t> hash_table_s;
      map<size_t,int> hash_table_words;
      int ssize = s.size() - words.size()*subsize;
      for (int i = 0; i <= s.size()-subsize; ++i)
      {
          hash_table_s.push_back(str_hash(s.substr(i, subsize)));
      }
      for (int i = 0; i < words.size(); ++i)
      {
          ++hash_table_words[str_hash(words[i])];
      }
      for (int i = 0; i <= ssize;)
      {
          if (findwords(hash_table_s, i, subsize, hash_table_words,words.size()))
          {
              result.push_back(i);
          }
          ++i;
      }
      return result;
  }
  bool findwords(vector<size_t>& hash_table_s, int index, int incre, map<size_t, int> & hash_table_words,int wordssize)
  {
      map<size_t, int>  temp;
      for (int i = 0; i < wordssize; ++i)
      {
          auto iter = hash_table_words.find(hash_table_s[index]);
          if (iter != hash_table_words.end())
          {
              int count = ++temp[iter->first];
              if (count <= iter->second)
              {
                  index += incre;
              }
              else
                  return false;
          }
          else
              return false;
      }
      return true;
  }
  //Runtime: 320 ms
  vector<int> findSubstring3(string s, vector<string>& words)
  {
      vector<int> result;
      if (s.size() == 0 || words.size() == 0)
          return result;
      if (s.size() < words[0].size())
          return result;
      int subsize = words[0].size();
      hash<string> str_hash;
      vector<size_t> hash_table_s, hash_table_words;
      int ssize = s.size() - words.size()*subsize;
      for (int i = 0; i <= s.size() - subsize; ++i)
      {
          hash_table_s.push_back(str_hash(s.substr(i, subsize)));
      }
      for (int i = 0; i < words.size(); ++i)
      {
          hash_table_words.push_back(str_hash(words[i]));
      }
      sort(hash_table_words.begin(), hash_table_words.end());
      vector<size_t> temphash(hash_table_words.size(), 0);
      for (int i = 0; i <= ssize;++i)
      {
          if (binary_search(hash_table_words.begin(), hash_table_words.end(), hash_table_s[i]))
          {
              for (int j = 0; j < words.size(); ++j)
              {
                  temphash[j] = hash_table_s[i + j*subsize];
              }
              sort(temphash.begin(), temphash.end());
              if (temphash == hash_table_words)
                  result.push_back(i);
          }
      }
      return result;
  }
};
int main(int argc, char const *argv[])
{
    Solution s;
    string str = "aaaaaaaa";
    string s1 = "aa";
    string s2 = "aa";
    string s3 = "aa";
    vector<string> vecs;
    vecs.push_back(s1);
    vecs.push_back(s2);
    vecs.push_back(s3);
    auto index = s.findSubstring(str, vecs);
    for (auto &c : index)
        cout << c << "  ";
    cout<<endl;
    index=s.findSubstring2(str, vecs);
    for (auto &c : index)
        cout << c << "  ";
    cout<<endl;
    index=s.findSubstring3(str, vecs);
    for (auto &c : index)
        cout << c << "  ";
    cout<<endl;
    return 0;
}

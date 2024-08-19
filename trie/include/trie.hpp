#pragma once

#include <string>
#include <map>
#include <initializer_list>
#include <memory>

template <class T> class trie {
public:
	trie(std::initializer_list<std::pair<std::wstring, T>> map) {
		for (auto p : map) {
			this->add(p.first, p.second);
		}
	};

	std::shared_ptr<T> search(std::wstring src, int& index, std::map<wchar_t, wchar_t> replace_list = {}) {
		int i = index;
		return this->_search(src, index, i, replace_list);
	}

	bool has(wchar_t c) {
		if (this->children.find(c) != this->children.end()) {
			return true;
		}
		else {
			return false;
		}
	}

	trie<T>* get(wchar_t c) {
		return this->children[c]; // check exsits
	}

	std::shared_ptr<T> val;

	/*
	void view(int indent) {
		if (this->val) {
			std::cout << *this->val;
		}
		std::cout << std::endl;
		for (auto p : this->children) {
			for (int i = 0; i < indent; i += 1) {
				std::wcout << L"\t";
			}
			std::wcout << p.first;
			p.second->view(indent + 1);
		}
	}
	*/

private:
	std::map<wchar_t, trie<T>* > children;

	void add(std::wstring key, T val) {
		if (key.length() == 0) {
			this->val = std::make_shared<T> (val);		
		}
		else {
			if (this->children.find(key[0]) == this->children.end()) {
				this->children[key[0]] = new trie<T> {};
			}
			this->children[key[0]]->add(key.substr(1), val);
		}
	};

	std::shared_ptr<T> _search(const std::wstring& src, int& index, int i, std::map<wchar_t, wchar_t>& replace_list) {
		std::shared_ptr<T> result = nullptr;

		if (i < src.length()) {
			wchar_t ch = src[i];
			if (replace_list.find(ch) != replace_list.end()) {
				ch = replace_list[ch];
			}
			if (this->children.find(ch) != this->children.end()) {
				result = this->children[ch]->_search(src, index, i+1, replace_list);
			}
			if (result == nullptr) {
				if (this->val != nullptr) {
					result = this->val;
					index = i;
				}
			}
		}
		else {
			if (this->val != nullptr) {
				result = this->val;
				index = i;
			}
		}

		return result;
	}

};
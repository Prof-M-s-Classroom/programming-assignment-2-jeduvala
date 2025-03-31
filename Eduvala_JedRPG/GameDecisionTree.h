#ifndef GAMEDECISIONTREE_H
#define GAMEDECISIONTREE_H

#include <unordered_map>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Node.h"
#include "Story.h"

template <typename T>
class GameDecisionTree {
private:
    Node<T>* root;

public:
    // TODO: Constructor
    GameDecisionTree() : root(nullptr) {}

    // TODO: Function to load story data from a text file and build the binary tree
    void loadStoryFromFile(const std::string& filename, char delimiter) {
        ifstream storyFile(filename);

        string fileLine;

        unordered_map<int, Node<T>*> events;

        while (getline(storyFile, fileLine)) {
            stringstream sstream(fileLine);

            string eventString;
            string description;
            string leftString;
            string rightString;

            getline(sstream, eventString, delimiter);
            getline(sstream, description, delimiter);
            getline(sstream, leftString, delimiter);
            getline(sstream, rightString);

            int eventNum = stoi(eventString);
            int leftNum = stoi(leftString);
            int rightNum = stoi(rightString);

            Node<T> *event = new Node<T>(Story(description, eventNum, leftNum, rightNum));

            events.emplace(eventNum, event);
        }

        if (events.find(1) != events.end()) {
            root = events.find(1)->second;

            for (auto pair: events) {
                pair.second->left = events.find(pair.second->data.leftEventNumber) != events.end() ?
                    events.find(pair.second->data.leftEventNumber)->second : nullptr;

                pair.second->right = events.find(pair.second->data.rightEventNumber) != events.end() ?
                    events.find(pair.second->data.rightEventNumber)->second : nullptr;

            }
        }
    }


    // TODO: Function to start the game and traverse the tree based on user input
    void playGame() {
        if (root == nullptr) {
            cerr << "No Story Loaded" << endl;
        }
        else {
            Node<T> *event = root;

            while (event != nullptr && (event->left != nullptr || event->right != nullptr)) {
                cout << event->data.description << "Do you: " << endl;

                if (event->left != nullptr) {
                    cout << "1. " << event->left->data.description << endl;
                }
                if (event->right != nullptr) {
                    cout << "2. " << event->right->data.description << endl;
                }

                int choice;

                cout << "Enter choice: ";
                cin >> choice;

                while (cin.fail() || choice < 1 || choice > 2 ||
                        (choice == 1 && event->left == nullptr) || (choice == 2 && event->right == nullptr)) {

                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    cout << "Invalid, enter choice: ";
                    cin >> choice;
                }

                if (choice == 1) {
                    event = event->left;
                }
                else {
                    event = event->right;
                }
            }

            cout << event->data.description << endl;

            cout << "You have reached the end of this path in the story." << endl;
        }
    }
};

#endif // GAMEDECISIONTREE_H
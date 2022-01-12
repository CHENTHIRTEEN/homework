//
// Created by 10303 on 2021/12/20.
//

#ifndef INC_07_TREE_H
#define INC_07_TREE_H

template<typename T>
struct node{
    T key_value;
    node *p_left;
    node *p_right;
};

template<typename T>
node<T> *init(){
    node<char> *tree = new node<char>;
    node<char> *p_node;
    p_node = new node<char>;
    node<char> *left = new node<char>;
    node<char> *right = new node<char>;
    node<char> *t = new node<char>;
    left->key_value = 'c';
    right->key_value = 'd';
    p_node->key_value = '-';
    p_node->p_left = left;
    p_node->p_right = right;
    right = p_node;
    left = new node<char>;
    left->key_value = 'b';
    p_node = new node<char>;
    p_node->key_value = '*';
    p_node->p_left = left;
    p_node->p_right = right;
    right = p_node;
    left = new node<char>;
    left->key_value = 'a';
    p_node = new node<char>;
    p_node->key_value = '+';
    p_node->p_left = left;
    p_node->p_right = right;
    tree->key_value = '-';
    tree->p_left = p_node;
    tree->p_right = new node<char>;
    tree->p_right->key_value = '/';
    tree->p_right->p_left = new node<char>;
    tree->p_right->p_left->key_value = 'e';
    tree->p_right->p_right->key_value = 'f';
    return tree;
}


#endif //INC_07_TREE_H

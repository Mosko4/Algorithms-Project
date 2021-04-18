#pragma once

struct Item {
	int data; //vertex
	int key; //d[vertex]

	Item() : data(-1), key(-1) {}
	Item(int d, int k) : data(d), key(k) {}
};
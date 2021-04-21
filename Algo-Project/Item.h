#pragma once

struct Item {
	int data; //vertex
	float key; //d[vertex]

	Item() : data(-1), key(-1) {}
	Item(int d, float k) : data(d), key(k) {}
};
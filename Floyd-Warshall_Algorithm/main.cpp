/* Полный ориентированный взвешенный граф задан матрицей смежности.Постройте матрицу
кратчайших путей между его вершинами.
Гарантируется, что в графе нет циклов отрицательного веса.
Формат входного файла
В первой строке вводится единственное число 𝑁(1 6 𝑁 6 100) — количество вершин графа.В
следующих 𝑁 строках по 𝑁 чисел задается матрица смежности графа(𝑗 - ое число в 𝑖 - ой строке —
вес ребра из вершины 𝑖 в вершину 𝑗).Все числа по модулю не превышают 100. На главной диагонали
матрицы — всегда нули.
Работает за O(E^3)*/


#include <fstream>
#include <vector>
#include "FullGraph.h"

int main() 
{
	std::fstream file;
	file.open("floyd.in", std::fstream::in);
	numeric VerticesQuantity;
	file >> VerticesQuantity;
	FullGraph G(VerticesQuantity);
	for (numeric i = 0; i < VerticesQuantity; ++i)
	{
		for (numeric j = 0; j < VerticesQuantity; ++j)
		{
			weightRange edgeWeight;
			file >> edgeWeight;
			G.add_edge(i, j, edgeWeight);
		}
	}
	file.close();

	auto distances(G.FloydWarshallAlgorithm());
	file.open("floyd.out", std::fstream::out);
	for (numeric i = 0; i < VerticesQuantity; ++i)
	{
		for (numeric j = 0; j < VerticesQuantity-1; ++j)
		{
			file << distances[i][j] << " ";
		}
		file << distances[i][VerticesQuantity-1];
		file << std::endl;
	}
	file.close();
}

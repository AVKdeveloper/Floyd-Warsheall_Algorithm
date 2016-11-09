#ifndef FULLGRAPH
#define FULLGRAPH

#include <vector>
#include <algorithm>

typedef long numeric;
typedef long weightRange;

class FullGraph
{
	numeric verticesNumber; //���������� ������
	std::vector<std::vector<weightRange>> edges; //������� ���������
public:
	FullGraph(const numeric& verticesNumber_); //����������� �� ���������� ������ 
	void add_edge(const numeric& numberVertexFrom, const numeric& numberVertexTo, const weightRange& weight);//���������� �����
	std::vector<std::vector<weightRange>> FloydWarshallAlgorithm() const;//�������� ������ ���������� ����� ����� ����� ������ ������
};

FullGraph::FullGraph(const numeric& verticesNumber_)
	: verticesNumber(verticesNumber_)
{
	edges.resize(verticesNumber);
	for (numeric i = 0; i < verticesNumber; ++i)
	{
		edges[i].resize(verticesNumber);
	}
}

void FullGraph::add_edge(const numeric& numberVertexFrom, const numeric& numberVertexTo, const weightRange& weight)
{
	edges[numberVertexFrom][numberVertexTo] = weight;
}

std::vector<std::vector<weightRange>> FullGraph::FloydWarshallAlgorithm() const
{
	std::vector<std::vector<weightRange>> distances;
	distances.resize(verticesNumber);
	for (numeric i = 0; i < verticesNumber; ++i)
	{
		distances[i].resize(verticesNumber);
	}
	for (numeric i = 0; i < verticesNumber; ++i)
	{
		for (numeric j = 0; j < verticesNumber; ++j)
		{
			distances[i][j] = edges[i][j];
			
		}
	}

	for (numeric i = 0; i < verticesNumber; ++i) //���� �� ������ ����� ������� ��-�� {0, 1, ..., i}
	{
		for (numeric u = 0; u < verticesNumber; ++u) //���������� �� ������� u
		{
			for (numeric v = 0; v < verticesNumber; ++v) // ���������� �� ������� v
			{
				distances[u][v] = std::min(distances[u][v], distances[u][i] + distances[i][v]);
			}
		}
	}
	return distances;
}

#endif

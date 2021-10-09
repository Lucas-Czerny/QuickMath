#include "../dependencies.h"

namespace qmath
{
	mat4x4 mat4x4::identity = { {
		{ 1.0f, 0.0f, 0.0f, 0.0f },
		{ 0.0f, 1.0f, 0.0f, 0.0f },
		{ 0.0f, 0.0f, 1.0f, 0.0f },
		{ 0.0f, 0.0f, 0.0f, 1.0f }
	} };

	mat4x4::mat4x4(float value)
	{
		m_Rows = mat4x4::identity * value;
	}

	mat4x4::mat4x4(const square_array_4d& rows)
		: m_Rows(rows) {}

	mat4x4::mat4x4(const std::initializer_list<std::initializer_list<float>>& rows)
	{
		ASSERT(rows.size() == 4, "A 4x4 matrix must have 4 rows!");

		int i = 0;
		for (const std::initializer_list<float>& row : rows)
		{
			ASSERT(row.size() == 4, "A 4x4 must have 4 columns!");

			std::copy(row.begin(), row.end(), m_Rows[i].begin());
			i++;
		}
	}

	void mat4x4::transpose()
	{
		square_array_4d columns;

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				columns[i][j] = m_Rows[j][i];
			}
		}

		m_Rows = columns;
	}

	std::string mat4x4::string() const
	{
		std::stringstream output;
		
		output << "{ ";

		for (int i = 0; i < 4; i++)
		{
			output << "{ ";

			for (int j = 0; j < 4; j++)
			{
				output << m_Rows[i][j];
				if (j != 3) output << ", ";
			}

			output << " }";
			if (i != 3) output << ", ";
		}

		output << " }";

		return output.str();
	}

	std::ostream& operator<<(std::ostream& os, const mat4x4& mat)
	{
		os << mat.string();
		return os;
	}

	array<4>& mat4x4::operator[](int index)
	{
		return m_Rows[index];
	}

	const array<4>& mat4x4::operator[](int index) const
	{
		return m_Rows[index];
	}

	mat4x4 mat4x4::operator+(const mat4x4& other)
	{
		mat4x4 result = *this;

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				result[i][j] += other[i][j];
			}
		}

		return result;
	}

	mat4x4 mat4x4::operator-(const mat4x4& other)
	{
		mat4x4 result = *this;

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				result[i][j] -= other[i][j];
			}
		}

		return result;
	}

	mat4x4 mat4x4::operator*(float value)
	{
		mat4x4 result = *this;

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				result[i][j] *= value;
			}
		}

		return result;
	}

	mat4x4 mat4x4::operator*(const mat4x4 other)
	{
		mat4x4 result;
		
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				vec4 column = { other.m_Rows[0][j], other.m_Rows[1][j], other.m_Rows[2][j], other.m_Rows[3][j] };
				result[i][j] = dot_product((vec4&)m_Rows[i], column);
			}
		}

		return result;
	}

	vec4 mat4x4::operator*(vec4 other)
	{
		vec4 result(0.0f);

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				result[i] += m_Rows[i][j] * other[j];
			}
		}

		return result;
	}

	mat4x4::operator square_array_4d() const
	{
		return m_Rows;
	}
}
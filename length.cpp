#include "length.h"
#include "exprtk.h"

using namespace std;

int main()
{
	const int SZ = 100; //�ַ��������С
	char buf[SZ];

	ifstream in("input.txt");
	assure(in, "input.txt");
	ofstream out("output.txt");
	assure(out, "output.txt");

	map<string, double> conversionTable;

	while(in.getline(buf, SZ))
	{
		if(buf[0] == '\0')
			break;              //ת����ʽ��������

		istringstream strStream(buf);
		int i = 0;
		string unitName;
		string equalSign;
		double valInMeters;
		string meterSign;
		strStream >> i >> unitName >> equalSign >> valInMeters >> meterSign;
		assert((i == 1) && (equalSign == "=") && (meterSign == "m"));
		
		conversionTable[unitName] = valInMeters;
		conversionTable[unitName + "s"] = valInMeters;
		conversionTable[unitName + "es"] = valInMeters;
		if(unitName == "foot")
			conversionTable["feet"] = valInMeters;
	}

	out << "tingsoft@qq.com" << endl;
	out << endl;

	out.setf(ios::fixed);
	out.setf(ios::showpoint);

	//double previous_num, now_num;
	while(in.getline(buf, SZ))
	{
		if(buf[0] == '\0')
			break;              //����������������
		string formulaStr;
		string token;
		istringstream ss(buf);
		while(ss >> token)
		{
			//����ÿ��token������ǳ��ȵ�λ���������ձ��ʽ��ת���� ���Զ�Ӧ���� ����ʽ
			if(conversionTable.find(token) != conversionTable.end())
			{
				ostringstream ostr;
				ostr << conversionTable.at(token);
				formulaStr.append("*" + ostr.str());
			}
			else
			{
				formulaStr.append(token);
			}
		}
		//cout << formulaStr << endl;

		//�����ı��ʽʹ�� exprTk ��ѧ���������
		exprtk::symbol_table<double> symbol_table;
		symbol_table.add_constants();

		exprtk::expression<double> expression;
		expression.register_symbol_table(symbol_table);

		exprtk::parser<double> parser;
		parser.compile(formulaStr,expression);

		out << setprecision(2) << expression.value() << " m" << endl;
	}

	return EXIT_SUCCESS;
}
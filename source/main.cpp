int main() {
try 
{
	stack<int> st; 
	int ct = 0;
	char ch;
	while (ct++<10)
	{
		cin >> ch;
		st.push(ch); // помещаем элементы в стек
	}
}
    
catch (const exception& e)  	//обработка исключений
{
	cout << e.what() << endl;
}
	return 0;
}

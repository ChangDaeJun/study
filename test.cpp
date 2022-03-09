{
	vector<int> divide;

	int min = a[0];
	divide.push_back(0);
	divide.push_back(0);
	bool circle = false;
	for(int i = 1; i < a.size(); i++)
	{
		if(a[i] < min)
		{
			min = a[i];
			divide.clear();
			divide.push_back(0);
			divide.push_back(i);
			divide.push_back(i);
			divide.push_back(i);
			circle = false;
		}
		else if(a[i] == min)
		{	
			if(circle == false)
			{
				divide.pop_back();
				divide.pop_back();	
				divide.push_back(i);
				divide.push_back(i);
			}
			else
			{
				divide.pop_back();
				divide.push_back(i);
				divide.push_back(i);
				divide.push_back(i);
				circle = false;
			}
		}
		else
		{
			divide.pop_back();
			divide.push_back(i);
			circle = true;
		}
	}
}

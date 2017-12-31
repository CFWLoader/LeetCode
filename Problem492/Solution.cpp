class Solution {
public:
    vector<int> constructRectangle(int area) {
    	
	int wid = sqrt(area);
	
	int len = area / wid;
	
	while(len * wid < area){
		
		--wid;
		
		len = area / wid;
		
	}
	
	return vector<int>({len, wid});
	}
};

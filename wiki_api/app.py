import requests
 
 
# function to parse data from wikipedia 
def get_content(article_name):
	title = article_name
	url = 'https://en.wikipedia.org/w/api.php'
	params = {
		"action": "query",
		"format": "json",
		"prop": "revisions",
		"meta": "",
		"titles": title,
		"formatversion": "2",
		"rvprop": "content",
		"rvslots": "*"
	}
	response = requests.get(url, params=params)
	return response.json()
	
	
# function to clean parsed data
def merge_contents(data):
	content = data["query"]["pages"][0]["revisions"][0]["slots"]["main"]["content"]
	return content
	
	
data = get_content("Linux")
clean_data = merge_contents(data)
print(clean_data)

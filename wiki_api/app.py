import requests
import re
 
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
  rm_chars = ["[[", "]]", "'''"]
  rm_space_chars = ["&nbsp;"]
  re_tags = re.compile('(<.*?>*(<.*?>))|(<.*?>)') 
  content = data["query"]["pages"][0]["revisions"][0]["slots"]["main"]["content"]
  content = re.sub(re_tags, '', content)
  for char in rm_chars:
        content = content.replace(char, '')
  for char in rm_space_chars:
  	content = content.replace(char, ' ')
  return content
  
data = get_content("Ozone layer")
clean_data = merge_contents(data)
print(clean_data)

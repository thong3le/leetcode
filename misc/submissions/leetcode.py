import cookielib, urllib2, re, sys, HTMLParser, os.path

LEETCODE_SESSION = "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJ1c2VybmFtZSI6InRob25nbGU5LjI3QGdtYWlsLmNvbSIsInVzZXJfc2x1ZyI6InRob25nbGU5MjdnbWFpbGNvbSIsIl9hdXRoX3VzZXJfaWQiOiI4ODM2MCIsInRpbWVzdGFtcCI6IjIwMTctMDQtMjcgMTg6MjE6MzguNDk1ODcxKzAwOjAwIiwiX2F1dGhfdXNlcl9iYWNrZW5kIjoiZGphbmdvLmNvbnRyaWIuYXV0aC5iYWNrZW5kcy5Nb2RlbEJhY2tlbmQiLCJpZCI6ODgzNjAsIl9zZXNzaW9uX2V4cGlyeSI6MTIwOTYwMCwiX2F1dGhfdXNlcl9oYXNoIjoiMjBhMWVmMzUxOTVhMzQ2YzBhNDNmMjliMzA1OWEwODAwMmMwMzZkZSIsImVtYWlsIjoidGhvbmdsZTkuMjdAZ21haWwuY29tIn0.cHP9gC6MsCJbnvPBzhftuRK9z_yLSYPpWVnXgKsHzbU"

if __name__ == '__main__':
    cj = cookielib.CookieJar()
    opener = urllib2.build_opener(urllib2.HTTPCookieProcessor(cj))
    parser = HTMLParser.HTMLParser()
    opener.addheaders = [('User-Agent', 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_9_0) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/31.0.1650.63 Safari/537.36'), ('Referer', 'http://oj.leetcode.com/accounts/login/'),
    	('Cookie', 'LEETCODE_SESSION=' + LEETCODE_SESSION + '; _ga=GA1.2.1984831265.1389075465; NRAGENT=tk=26e67c3be080fab2'),]
	
    page = 'https://oj.leetcode.com/submissions/#/' + `1`
    print page
    resp = opener.open(page)
    content = resp.read()
    print content
    url_pattern = re.compile("[0-9]*/\"><strong>Accepted</strong></a>")
    for match in url_pattern.findall(content):
        print match

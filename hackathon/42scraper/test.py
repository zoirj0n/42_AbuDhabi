from selenium import webdriver
import time
import config
from selenium import webdriver
from selenium.webdriver.support.ui import WebDriverWait


# Main Function
if __name__ == '__main__':

	options = webdriver.ChromeOptions()
	options.add_argument("--start-maximized")
	options.add_argument('--log-level=3')

	# Provide the path of chromedriver present on your system.
	driver = webdriver.Chrome(executable_path="/Users/eve/Desktop/chromedriver",
							chrome_options=options)
	driver.set_window_size(1920,1080)

	# Send a get request to the url

	# 42 credentials
	username = config.username
	password = config.password
	# head to github login page
	driver.get("https://signin.intra.42.fr/users/sign_in")
	# find username/email field and send the username itself to the input field
	driver.find_element_by_id("user_login").send_keys(username)
	# find password input field and insert password as well
	driver.find_element_by_id("user_password").send_keys(password)
	# click login button
	driver.find_element_by_name("commit").click()

	time.sleep(60)
	driver.quit()
	print("Done")

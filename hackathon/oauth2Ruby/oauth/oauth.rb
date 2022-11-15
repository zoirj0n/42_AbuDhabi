require 'oauth2'
require 'json'
UID = "u-s4t2ud-da794d8b0c77ed8311ec73a40b2ae46589bd1903a2aedba7bf5e07dd9f247590"
SECRET = "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"
campus_id = 43
username = 'zosobiro'
client = OAuth2::Client.new(UID, SECRET, site: "https://api.intra.42.fr")
token = client.client_credentials.get_token
print(token)
response = token.get("/v2/campus/#{campus_id}/events")
response.status
File.open('data.json', 'w') do |f|
  f.write(JSON.pretty_generate(response.parsed))
end
print(JSON.pretty_generate(response.parsed))
client = OAuth2::Client.new(UID, SECRET, site: "https://api.intra.42.fr")
token = client.client_credentials.get_token
print(token)
response = token.get("/v2/campus/#{campus_id}/events")
response.status
File.open('data.json', 'w') do |f|
  f.write(JSON.pretty_generate(response.parsed))
end
print(JSON.pretty_generate(response.parsed))

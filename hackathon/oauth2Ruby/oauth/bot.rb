require 'telegram/bot'
require 'oauth2'
require 'json'
require './assets/functions/functions'
require './assets/config/config'

# config = Configuration.new
test = Test.new

# bot_token = config.configurations['bot_token']
# print(bot_token)
# print("sad")
# UID = get_uid
# SECRET = get_secret
# campus_id = ENV['campus_id']
UID = "u-s4t2ud-da794d8b0c77ed8311ec73a40b2ae46589bd1903a2aedba7bf5e07dd9f247590"
SECRET = "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"
campus_id = 43
username = 'zosobiro'
bot_token = "5793746832:AAG30ekfHBKEQjb62rUvTK67tt71t4vzs1k"


Telegram::Bot::Client.run(bot_token) do |bot|
  bot.listen do |message|
    case message
    when Telegram::Bot::Types::CallbackQuery
      test.callbackHandler(bot, message)
    when Telegram::Bot::Types::Message
      test.welcome(bot, message)
    end
  end
end
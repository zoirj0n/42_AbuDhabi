require 'telegram/bot'
class Test
  def callbackHandler(bot, message)
    # Here you can handle your callbacks from inline buttons
     if message.data == 'check_in'
          bot.api.send_message(chat_id: message.from.id, text:"Check in")
     end
    if message.data == 'info'
      bot.api.send_message(chat_id: message.from.id, text:"Hello from another class")
      # bot.api.send_message(chat_id: message.from.id, text: "Information")
    end
    if message.data == 'email'
      bot.api.send_message(chat_id: message.from.id, text: "Emails")
    end
    if message.data == 'slot'
      bot.api.send_message(chat_id: message.from.id, text: "Slots")
    end
    if message.data == 'event'
      bot.api.send_message(chat_id: message.from.id, text: "Events")
    end
    if message.data == 'news'
      bot.api.send_message(chat_id: message.from.id, text: "News")
    end
    if message.data == 'parking'
      bot.api.send_message(chat_id: message.from.id, text: "Parking")
    end
    if message.data == 'library'
      bot.api.send_message(chat_id: message.from.id, text: "Library")
    end
  end
  def welcome(bot, message)
    kb = [
      Telegram::Bot::Types::InlineKeyboardButton.new(text: 'Check in', callback_data: 'check_in'),
      Telegram::Bot::Types::InlineKeyboardButton.new(text: '42 Information', callback_data: 'info'),
      Telegram::Bot::Types::InlineKeyboardButton.new(text: 'Emails', callback_data: 'email'),
      Telegram::Bot::Types::InlineKeyboardButton.new(text: 'Slot management', callback_data: 'slot'),
      Telegram::Bot::Types::InlineKeyboardButton.new(text: 'Events', callback_data: 'event'),
      Telegram::Bot::Types::InlineKeyboardButton.new(text: 'News', callback_data: 'news'),
      Telegram::Bot::Types::InlineKeyboardButton.new(text: 'Parking', callback_data: 'parking'),
      Telegram::Bot::Types::InlineKeyboardButton.new(text: 'Library', callback_data: 'library'),
    ]
    markup = Telegram::Bot::Types::InlineKeyboardMarkup.new(inline_keyboard: kb)
    bot.api.send_message(chat_id: message.chat.id, text: 'Hello this is me 42Automation bot, what can I help you?')
    bot.api.send_message(chat_id: message.chat.id, text: 'Please select 👇', reply_markup: markup)
  end
end
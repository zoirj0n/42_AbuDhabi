class Configuration
  def configurations
    YAML.safe_load(ERB.new(File.read('config.yml')).result)
  end
end
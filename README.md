<p>
  Provides an OpenAI Speech-To-Text service for the Freeswitch. <br>
  Also capable to work with <a href="https://github.com/akscf/whisperd target="_blank">whisperd</a>
</p>

### Usage example
```XML
<extension name="openai-asr">
  <condition field="destination_number" expression="^(3222)$">
    <action application="answer"/>
    <action application="play_and_detect_speech" data="/tmp/test2.wav detect:openai"/>
    <action application="sleep" data="1000"/>
    <action application="log" data="CRIT SPEECH_RESULT=${detect_speech_result}"/>
    <action application="hangup"/>
 </condition>
</extension>
```

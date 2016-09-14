# muck
Drupal development stuff




# Webtools twitter

## Description
Muck Webtools Twitter allows embedding tweets inside the body of a node.
See Webtools docs https://webgate.ec.europa.eu/fpfis/wikis/x/QKUjBg

## Features
* Converts a twitter link into the webtools snippet that expands to an embedded tweet

## Pre-requisites
To use webtools js libraries several conditions must be met:

* Webtools load.js must be loaded as https:// . http:// will result in access denied.
* The domain names should contain ec.europa.eu . E.g. http://mapper.val.ec.europa.eu. Other domain names will reuslt in access denied.
* For the staging server include the wtenv parameters wtenv=acc in the url. E.g. http://mapper.val.ec.europa.eu/node/12?wtenv=acc . If missing it results in access denied.
* For the staging server: login through browser with htaccess username and password. Otherwise, you know what happens.

## Mapeditor configuration & usage

### Configuration
1. Enable the module muck
2. Configure a text format at admin/config/content/formats
3. Enable the "Embed tweets" filter
4. Verify the correct order of filters under "Filter processing order". The "Embed tweets" filter must be below "Limit allowed HTML tags", "Convert line breaks into HTML" and "Correct faulty and chopped off HTML" but it must be higher than "Convert URLs into links".
   All these filters work on HTML tags so the order can make or break the embedded tweets
5. Configure the module at admin/config/system/muck/twitter
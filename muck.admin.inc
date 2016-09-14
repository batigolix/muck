<?php
/**
 * @file
 * Administration forms for the Muck module.
 */

/**
 * Provides the Webtools Twitter settings form.
 *
 * See webtools documention at
 * https://webgate.ec.europa.eu/fpfis/wikis/x/kaUjBg
 */
function _muck_twitter_settings_form() {
  $form = array();
  $form['general'] = array(
    '#type' => 'fieldset',
    '#title' => t('General settings for Webtools Twitter'),
  );
  $form['user'] = array(
    '#type' => 'fieldset',
    '#title' => t('Settings for Webtools Twitter User timeline'),
  );
  $form['general']['muck_webtools_smartloader_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Smartloader Protocol-Relative URL'),
    '#default_value' => variable_get('muck_webtools_smartloader_url', '//europa.eu/webtools/load.js'),
    '#description' => t("The URL of the webtools smartloader script. e.g. '//europa.eu/webtools/load.js'"),
    '#required' => TRUE,
  );
  $form['general']['muck_webtools_display_user'] = array(
    '#type' => 'checkbox',
    '#title' => t('Display user name'),
    '#default_value' => variable_get('muck_webtools_display_user', TRUE),
    '#description' => t('Displays the user name in an embedded tweet'),
  );
  $form['general']['muck_webtools_display_user_pic'] = array(
    '#type' => 'checkbox',
    '#title' => t('Display profile picture'),
    '#default_value' => variable_get('muck_webtools_display_user_pic', 'true'),
    '#description' => t('Displays the user profile picture in an embedded tweet'),
  );
  $form['general']['muck_webtools_auto_expand_photo'] = array(
    '#type' => 'checkbox',
    '#title' => t('Expand image'),
    '#default_value' => variable_get('muck_webtools_auto_expand_photo', TRUE),
    '#description' => t('Automatically expands an image in an embedded tweet'),
  );
  $form['user']['muck_webtools_count'] = array(
    '#type' => 'textfield',
    '#size' => '12',
    '#title' => t('Amount'),
    '#required' => true,
    '#default_value' => variable_get('muck_webtools_count', 3),
    '#description' => t('Number of tweets to be shown in the user timeline. The amount must be higher than 0 and lower than 31'),
    '#element_validate' => array('element_validate_number', '_muck_twitter_validate_amount'),
  );
  $form['user']['muck_webtools_include_rts'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show retweets'),
    '#default_value' => variable_get('muck_webtools_include_rts', TRUE),
    '#description' => t("Shows retweets in the user's timeline"),
  );
  $form['user']['muck_webtools_rts_display_original'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show retweet profile'),
    '#default_value' => variable_get('muck_webtools_rts_display_original', TRUE),
    '#description' => t('Shows the original profile of a retweet'),
  );
  $form['user']['muck_webtools_show_replies'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show replies'),
    '#default_value' => variable_get('muck_webtools_show_replies', TRUE),
    '#description' => t("Shows replies in the user's timeline"),
  );
  $form['user']['muck_webtools_tweet_more_btn'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show more'),
    '#default_value' => variable_get('muck_webtools_tweet_more_btn', TRUE),
    '#description' => t('Adds a link "More tweets" after the widget. It opens the user timeline page on twitter.com, including all the tweets, retweets and replies'),
  );
  return system_settings_form($form);
}

/**
 * Implements hook_validate().
 */
function _muck_twitter_validate_amount($element, &$form_state, $form) {
  if ($element['#value'] > 30 || $element['#value'] < 1) {
    form_error($element, t('The amount must be higher than 0 and lower than 31'));
  }
}

<?php

/**
 * simple_content_contact.admin.inc
 * Outputs the admin forms
 *
 * Author: Luís Pedro Algarvio
 * lpalgarvio, lpca
 * lp.algarvio@gmail.com
 * http://lp.algarvio.org
 *
 * Javali ADSI, Lda.
 * http://www.javali.pt
 */


/**
 * Implements hook_form().
 * 
 * Contact section form
 *
 */
function simple_content_contact_form($form, &$form_state) {
  $form = array();

  // Contact section Header
  $form['simple_content_contact_header'] = array(
    '#type' => 'textfield',
    '#weight' => '-20',
    '#title' => t('Header'),
    '#description' => t('Insert the contact section header.'),
    '#default_value' => variable_get('simple_content_contact_header', NULL),
    '#required' => FALSE,
    '#maxlength' => 40,
  );

  // Vertical tabs
  $form['simple_content_contact_group_main'] = array(
    '#type' => 'vertical_tabs',
    '#weight' => '-10',
  );

  // Fieldsets
  $form['simple_content_contact_group_entity'] = array(
    '#type' => 'fieldset',
    '#weight' => '1',
    '#title' => t('Entity'),
    '#collapsible' => TRUE,
    '#group' => 'simple_content_contact_group_main',
  );
  $form['simple_content_contact_group_location'] = array(
    '#type' => 'fieldset',
    '#weight' => '2',
    '#title' => t('Location'),
    '#collapsible' => TRUE,
    '#group' => 'simple_content_contact_group_main',
  );
  $form['simple_content_contact_group_mediums'] = array(
    '#type' => 'fieldset',
    '#weight' => '3',
    '#title' => t('Mediums'),
    '#collapsible' => TRUE,
    '#group' => 'simple_content_contact_group_main',
  );

  // Contact Title
  $form['simple_content_contact_group_entity']['simple_content_contact_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#description' => t('Insert the title.'),
    '#default_value' => variable_get('simple_content_contact_title', NULL),
    '#required' => FALSE,
    '#maxlength' => 30,
  );

  // Contact Postal address
  $form['simple_content_contact_group_location']['simple_content_contact_postal'] = array(
    '#type' => 'textarea',
    '#title' => t('Postal address'),
    '#description' => t('Insert the postal address.'),
    '#default_value' => variable_get('simple_content_contact_postal', NULL),
    '#required' => FALSE,
    '#rows' => 3,  
  );

  // Contact Country
  require_once DRUPAL_ROOT . '/includes/locale.inc';
  $form['simple_content_contact_group_location']['simple_content_contact_country'] = array(
    '#type' => 'select',
    '#title' => t('Country'),
    '#description' => t('Select the country.'),
    '#default_value' => variable_get('simple_content_contact_country', NULL),
    '#required' => FALSE,
    '#options' => country_get_list(),
  );

  // Contact Latitude
  $form['simple_content_contact_group_location']['simple_content_contact_latitude'] = array(
    '#type' => 'textfield',
    '#title' => t('Latitude'),
    '#description' => t('Insert the latitude for the Google Maps.'),
    '#default_value' => variable_get('simple_content_contact_latitude', NULL),
    '#required' => FALSE,
    '#maxlength' => 10,
  );

  // Contact Longitude
  $form['simple_content_contact_group_location']['simple_content_contact_longitude'] = array(
    '#type' => 'textfield',
    '#title' => t('Longitude'),
    '#description' => t('Insert the longitude for the Google Maps.'),
    '#default_value' => variable_get('simple_content_contact_longitude', NULL),
    '#required' => FALSE,
    '#maxlength' => 10,
  );

  // Contact Phone number
  $form['simple_content_contact_group_mediums']['simple_content_contact_phone'] = array(
    '#type' => 'textfield',
    '#title' => t('Phone number'),
    '#description' => t('Insert the phone number.'),
    '#default_value' => variable_get('simple_content_contact_phone', NULL),
    '#required' => FALSE,
    '#maxlength' => 21,
  );

  // Contact Fax number
  $form['simple_content_contact_group_mediums']['simple_content_contact_fax'] = array(
    '#type' => 'textfield',
    '#title' => t('Fax number'),
    '#description' => t('Insert the fax number.'),
    '#default_value' => variable_get('simple_content_contact_fax', NULL),
    '#required' => FALSE,
    '#maxlength' => 21,
  );

  // Contact Email address
  $form['simple_content_contact_group_mediums']['simple_content_contact_email'] = array(
    '#type' => 'textfield',
    '#title' => t('Email address'),
    '#description' => t('Insert the email address.'),
    '#default_value' => variable_get('simple_content_contact_email', NULL),
    '#required' => FALSE,
    '#maxlength' => 64,
  );

  $form['submit'] = array(
    '#type' => 'submit', 
    '#value' => t('Save configuration'),
  );

  return $form;
}


/**
 * Submit handler for form().
 * 
 * Contact section form
 *
 */
function simple_content_contact_form_submit($form, &$form_state) {

  // Contact Header
  variable_set('simple_content_contact_header', $form_state['values']['simple_content_contact_header']);

  // Contact Title
  variable_set('simple_content_contact_title', $form_state['values']['simple_content_contact_title']);

  // Contact Postal address
  variable_set('simple_content_contact_postal', $form_state['values']['simple_content_contact_postal']);

  // Contact Country
  variable_set('simple_content_contact_country', $form_state['values']['simple_content_contact_country']);

  // Contact Phone number
  variable_set('simple_content_contact_phone', $form_state['values']['simple_content_contact_phone']);

  // Contact Fax number
  variable_set('simple_content_contact_fax', $form_state['values']['simple_content_contact_fax']);

  // Contact Email address
  variable_set('simple_content_contact_email', $form_state['values']['simple_content_contact_email']);

  // Contact Latitude
  variable_set('simple_content_contact_latitude', $form_state['values']['simple_content_contact_latitude']);

  // Contact Longitude
  variable_set('simple_content_contact_longitude', $form_state['values']['simple_content_contact_longitude']);

}

all:
	gcc -g3 -c amf_ngap_procedures/amf_configuration_transfer_procedures.c -I.
	gcc -g3 -c amf_ngap_procedures/amf_interface_management_procedures.c -I.
	gcc -g3 -c amf_ngap_procedures/amf_location_reporting_procedures.c -I.
	gcc -g3 -c amf_ngap_procedures/amf_nrppa_transport_procedures.c -I.
	gcc -g3 -c amf_ngap_procedures/amf_paging_procedures.c -I.
	gcc -g3 -c amf_ngap_procedures/amf_pdu_session_management_procedures.c -I.
	gcc -g3 -c amf_ngap_procedures/amf_trace_procedures.c -I.
	gcc -g3 -c amf_ngap_procedures/amf_transport_of_nas_messages_procedures.c -I.
	gcc -g3 -c amf_ngap_procedures/amf_ue_capability_management_procedures.c -I.
	gcc -g3 -c amf_ngap_procedures/amf_ue_context_management_procedures.c -I.
	gcc -g3 -c amf_ngap_procedures/amf_ue_mobility_management_procedures.c -I.
	gcc -g3 -c amf_ngap_procedures/amf_ue_tnla_binding_procedures.c -I.
	gcc -g3 -c amf_ngap_procedures/amf_warning_message_transmission_procedures.c -I.
	gcc -g3 -c amf_config.c -I.
	gcc -g3 -c amf_core.c -I.
	gcc -g3 -o ngAmf amf_ngap_message_handlers.c app_amf.c *.o libsicore.so
	gcc -g3 -o ngRAN ran_ngap_message_handlers.c app_ngran.c app_ngap_test_data.c amf_core.c libsicore.so
	rm *.o